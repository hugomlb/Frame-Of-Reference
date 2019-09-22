#include "InFile.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <netinet/in.h>
#define END_OF_FILE -1
#define OK 0

InFile::InFile(const char* filename) {
  if (*filename == '-') {
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

int InFile::readNumbsToStartingAt(int amountOfNumb, Block *block, int position) { //PONER MUTEX
  file -> seekg(position, file -> beg);
  int fileState = OK;
  if (file -> tellg() >= size) {
    std::cout << "Te fuiste de mambo" << std::endl;
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

int InFile::readNumberTo(Block *block) {
  int fileState = isEOF();
  if (fileState == OK) {
    char* num = new char [4];
    file -> read(num, 4);
    uint32_t number;
    memcpy(&number, num, sizeof(char) * 4);
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

int InFile::isEOF() {
  int returnValue = OK;
  if (file -> eof()) {
    returnValue = END_OF_FILE;
  }
  return returnValue;
}

InFile::~InFile(){
  fd.close();
}
