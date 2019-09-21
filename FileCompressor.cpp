#include "FileCompressor.h"
#define END_OF_FILE -1
#define OK 0
#define NUMB_SIZE 4
#define AMOUNT_OF_THREADS 1 //HARDODEADO********************************************

FileCompressor::FileCompressor(InFile* in, ProtectedBlockQueue* queue,
    int numbsPerBlock):block(numbsPerBlock) {
  inFile = in;
  this -> queue = queue;
  this -> numbsPerBlock = numbsPerBlock;
}

void FileCompressor::compress() {
  int fileState = OK;
  int position = 0;
  while (fileState == OK) {
    fileState = inFile -> readNumbsToStartingAt(numbsPerBlock, &block, position);
    position += (numbsPerBlock * NUMB_SIZE * AMOUNT_OF_THREADS);
    if (!(block.hasSpace())) {
      BitBlock bitBlock = block.compressTo(queue);
      block.reset();
    }
  }
  queue -> done(true);
}

FileCompressor::~FileCompressor() {
}
