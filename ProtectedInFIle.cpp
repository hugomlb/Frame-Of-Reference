#include "ProtectedInFile.h"
#include <iostream>
#include <cstdint>
#include <netinet/in.h>
#define END_OF_FILE -1
#define OK 0
#define NUM_SIZE 4
#define CIN '-'

ProtectedInFile::ProtectedInFile(const char* filename) {
  if (*filename == CIN) {
    file = &std::cin;
  } else {
    fd = std::ifstream(filename, std::ios::in|std::ios::binary);
    file = &fd;
  }
  lastRead = 0;
  file -> seekg(0, file -> end);
  size = file -> tellg();
  file -> seekg(0, file -> beg);
}

int ProtectedInFile::readNumbsToStartingAt(Block *block, int position) {
  std::lock_guard<std::mutex> lock(mutex);
  file -> seekg(position, file -> beg);
  int fileState = OK;
  if (file -> tellg() >= size) {
    fileState = END_OF_FILE;
  }
  wasRead = false;
  while (block -> hasSpace() && fileState == OK) {
    fileState = readNumberTo(block);
  }
  while (block -> hasSpace() && wasRead) {
    block -> addNumber(lastRead);
  }
  return  fileState;
}

int ProtectedInFile::readNumberTo(Block *block) {
  int fileState = isEOF();
  if (fileState == OK) {
    uint32_t number;
    file -> read((char*) &number, NUM_SIZE);
    number = be32toh(number);
    fileState = isEOF();
    if (fileState == OK) {
      lastRead = number;
      block -> addNumber(lastRead);
      wasRead = true;
    }
  }
  return fileState;
}

int ProtectedInFile::isEOF() {
  int returnValue = OK;
  if (file -> eof()) {
    file -> clear();
    returnValue = END_OF_FILE;
  }
  return returnValue;
}

ProtectedInFile::~ProtectedInFile(){
}
