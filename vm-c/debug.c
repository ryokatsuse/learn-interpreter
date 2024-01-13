#include <stdio.h>

#include "chunk.h"
#include "debug.h"

static int simpleInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

void disassembleChunk(Chunk* chunk, const char* name) {
  printf("== %s ==\n", name);
  // ここでchunk->countは書き込まれたバイト数
  for(int offset = 0; offset < chunk->count;) {
    // ここでoffsetは読み込んだバイト数
    offset = disassembleInstruction(chunk, offset);
  }
}

int disassembleInstruction(Chunk* chunk, int offset) {
  printf("%04d ", offset);
  // ここでoffsetは命令のバイト数
  uint8_t instruction = chunk->code[offset];
  switch(instruction) {
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset + 1;
  }
}