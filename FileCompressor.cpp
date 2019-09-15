#include "FileCompressor.h"
#include <iostream>
#include <fstream>
using namespace std;

FileCompressor::FileCompressor(File* aFile) {
  this -> inFIle = aFile;
}

FileCompressor::~FileCompressor() {

}
