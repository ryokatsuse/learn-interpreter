#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

// growArrayをテキスト通りにやっても型名を直接渡すことができなかったため関数のプロトタイプを実装
void* growArray(void* array, size_t elementSize, int oldCount, int newCount);

#endif