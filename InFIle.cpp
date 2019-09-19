#include "InFile.h"
#include <iostream>
#include <istream>
#include <cstdint>
#include <cstring>
#include <netinet/in.h>
using namespace std;
#define END_OF_FILE -1
#define OK 0

InFile::InFile() {
  file = &cin;
  lastRead = 0;
  lectureNum = 0;
  /*if (file.is_open()) {
    file.seekg(0);
  } else {
    printf("%s\n", "No se pudo abrir el archivo");
  }*/
}

int InFile::readNumbsTo(Block *block, int amountOfNumb) {
  int fileState = isEOF();
  wasRead = false;
  while (block -> hasSpace() && fileState == OK) {
    fileState = readNumberTo(block);
  }
  while (block -> hasSpace() && wasRead) {
    block ->addNumber(lastRead);
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
}
