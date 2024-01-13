#include <stdlib.h>

#include "chunk.h"

// サイズを渡すようにする関数
void* growArray(void* array, size_t elementSize, int oldCount, int newCount) {
    return realloc(array, elementSize * newCount);
}

void initChunk(Chunk* chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  // この時点ではメモリは確保されていない
  chunk->code = NULL;
}

void writeChunk(Chunk* chunk, uint8_t byte) {
  if(chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    //型の代わりに型のサイズを渡す
    chunk->code = (uint8_t*)growArray(chunk->code, sizeof(uint8_t), oldCapacity, chunk->capacity);
  }
  chunk->code[chunk->count] = byte;
  chunk->count++;
}