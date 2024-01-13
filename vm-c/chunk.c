#include <stdlib.h>
#include "chunk.h"
#include "memory.h"

void* growArray(void* array, size_t elementSize, int oldCount, int newCount) {
    return realloc(array, elementSize * newCount);
}

void initChunk(Chunk* chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  // この時点ではメモリは確保されていない
  chunk->code = NULL;
  chunk->lines = NULL;
  initValueArray(&chunk->constants);
}

void freeChunk(Chunk* chunk) {
  FREE_ARRAY(chunk->code, chunk->capacity);
  FREE_ARRAY(chunk->lines, chunk->capacity);
  freeValueArray(&chunk->constants);
  initChunk(chunk);
}

void writeChunk(Chunk* chunk, uint8_t byte, int line) {
  if (chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code = GROW_ARRAY(chunk->code, uint8_t, oldCapacity, chunk->capacity);
    chunk->lines = GROW_ARRAY(chunk->lines, int, oldCapacity, chunk->capacity);
  }
  chunk->code[chunk->count] = byte;
  chunk->lines[chunk->count] = line;
  chunk->count++;
}

int addConstant(Chunk* chunk, Value value) {
  // メモリが足りない場合は拡張
  writeValueArray(&chunk->constants, value);
  // メモリ確保に成功したら値を書き込む
  return chunk->constants.count - 1;
}