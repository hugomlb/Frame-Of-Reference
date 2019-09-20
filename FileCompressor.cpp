#include "FileCompressor.h"
#define END_OF_FILE -1
#define OK 0

FileCompressor::FileCompressor(InFile* in, ProtectedBlockQueue* queue,
    int numbsPerBlock):block(numbsPerBlock) {
  inFile = in;
  this -> queue = queue;
  this -> numbsPerBlock = numbsPerBlock;
}

void FileCompressor::compress() {
  int fileState = OK;
  while (fileState == OK) {
    fileState = inFile -> readNumbsTo(&block, numbsPerBlock);
    if (!(block.hasSpace())) {
      BitBlock bitBlock = block.compress();
      queue -> push(bitBlock, false);
      block.reset();
    }
  }
  queue -> done(true);
}

FileCompressor::~FileCompressor() {
}
