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
}

void freeChunk(Chunk* chunk) {
  FREE_ARRAY(chunk->code, chunk->capacity);
  initChunk(chunk);
}

void writeChunk(Chunk* chunk, uint8_t byte) {
  if(chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code = (uint8_t*)growArray(chunk->code, sizeof(uint8_t), oldCapacity, chunk->capacity);
  }
  chunk->code[chunk->count] = byte;
  chunk->count++;
}