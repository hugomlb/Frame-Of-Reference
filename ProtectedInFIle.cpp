#include "ProtectedInFile.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <netinet/in.h>
#include "Lock.h"
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

int ProtectedInFile::readNumbsToStartingAt(int amountOfNumb, Block *block,
    int position) {
  mutex.lock();
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
  mutex.unlock();
  return  fileState;
}

int ProtectedInFile::readNumberTo(Block *block) {
  int fileState = isEOF();
  if (fileState == OK) {
    char* num = new char [NUM_SIZE];
    file -> read(num, NUM_SIZE);
    uint32_t number;
    memcpy(&number, num, sizeof(char) * NUM_SIZE);
    delete[] num;
    number = ntohl(number);
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
  if (fd.is_open()) {
    fd.close();
  }
}