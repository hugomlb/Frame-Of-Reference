#include "FileCompressor.h"
#include <iostream>
#include <fstream>
using namespace std;

FileCompressor::FileCompressor(File* aFile, int numbsPerBlock) {
  this -> inFile = aFile;
  block = new Block(numbsPerBlock);
}

void FileCompressor::compress() {
  int x = inFile -> readNumber();
  block -> addNumber(x);
}

FileCompressor::~FileCompressor() {
  delete block;
}
