#include "FileCompressor.h"
#define END_OF_FILE -1
#define OK 0
#define NUMB_SIZE 4

FileCompressor::FileCompressor(InFile* in, ProtectedBlockQueue* queue,
    int numbsPerBlock, int numbOfThreads, int myNumb):block(numbsPerBlock) {
  inFile = in;
  this -> queue = queue;
  this -> numbsPerBlock = numbsPerBlock;
  this -> numbOfThreads = numbOfThreads;
  this -> myNumb = myNumb;
}

void FileCompressor::run() {
  int fileState = OK;
  int position = (numbsPerBlock * NUMB_SIZE * myNumb);
  while (fileState == OK) {
    fileState = inFile -> readNumbsToStartingAt(numbsPerBlock, &block, position);
    position += (numbsPerBlock * NUMB_SIZE * numbOfThreads);
    if (!(block.hasSpace())) {
      BitBlock bitBlock = block.compressTo(queue);
      block.reset();
    }
  }
  queue -> done(true);
  std::cout<< "Termino: " << myNumb << std::endl;
}

FileCompressor::~FileCompressor() {
}
