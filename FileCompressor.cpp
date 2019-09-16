#include "FileCompressor.h"
#include <iostream>
#include <fstream>
using namespace std;
#define END_OF_FILE -1
#define OK 0

FileCompressor::FileCompressor(File* aFile, int numbsPerBlock) {
  this -> inFile = aFile;
  block = new Block(numbsPerBlock);
}

void FileCompressor::compress() {
  int fileState = OK;
  while (block -> hasSpace() && fileState == OK) {
    fileState = inFile -> readNumberTo(block);
  }
  block -> sustractMin();
}

FileCompressor::~FileCompressor() {
  delete block;
}
