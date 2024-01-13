#include <stdio.h>

#include "value.h"
#include "memory.h"

// 初期化
void initValueArray(ValueArray* array) {
  array->values = NULL;
  array->capacity = 0;
  array->count = 0;
}

// メモリ解放
void freeValueArray(ValueArray* array) {
  FREE_ARRAY(array->values, array->capacity);
  initValueArray(array);
}

// メモリ確保
void writeValueArray(ValueArray* array, Value value) {
  if (array->capacity < array->count + 1) {
    int oldCapacity = array->capacity;
    array->capacity = GROW_CAPACITY(oldCapacity);
    array->values = GROW_ARRAY(array->values, Value, oldCapacity, array->capacity);
  }
  array->values[array->count] = value;
  array->count++;
}

// 値を表示
void printValue(Value value) {
  printf("%g", value);
}