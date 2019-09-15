#include "FileCompressor.h"
#include <iostream>
#include <fstream>
using namespace std;

FileCompressor::FileCompressor(File* aFile, int numbsPerBlock) {
  this -> inFIle = aFile;
  this -> numbsPerBlock = numbsPerBlock;
}



FileCompressor::~FileCompressor() {

}
