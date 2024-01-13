#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"
#include <stdlib.h>

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity)*2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

#define FREE_ARRAY(pointer, oldCount) \
    freeArray(pointer, oldCount)

// growArrayをテキスト通りにやっても型名を直接渡すことができなかったため関数のプロトタイプを実装
void* growArray(void* array, size_t elementSize, int oldCount, int newCount);
// freeArray関数のプロトタイプ
void freeArray(void* array, int oldCount);

void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif