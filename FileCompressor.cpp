#include "FileCompressor.h"
#include <fstream>
using namespace std;
#define END_OF_FILE -1
#define OK 0

FileCompressor::FileCompressor(InFile* aFile, int numbsPerBlock) {
  inFile = aFile;
  this -> numbsPerBlock = numbsPerBlock;
  block = new Block(numbsPerBlock);
}

void FileCompressor::compress() {
  int fileState = OK;
  while (fileState == OK) {
    fileState = inFile->readNumbsTo(block, numbsPerBlock);
    if (!(block->hasSpace())) {
      block->subtractMin();
      block->reset();
    }
  }
}

FileCompressor::~FileCompressor() {
  delete block;
}
