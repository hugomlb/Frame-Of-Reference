#include "InFile.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#include <netinet/in.h>
using namespace std;
#define END_OF_FILE -1
#define OK 0

InFile::InFile() {
  this -> file = ifstream("alot", ios::in|ios::binary);
  lastRead = 0;
  if (this -> file.is_open()) {
    this -> file.seekg(0);
  } else {
    printf("%s\n", "No se pudo abrir el archivo");
  }
}

int InFile::readNumbsTo(Block *block, int amountOfNumb) {
  int fileState = isEOF();
  while (block -> hasSpace() && fileState == OK) {
    fileState = readNumberTo(block);
    cout << "Poniendo: " << lastRead << endl;
  }
  while (block -> hasSpace()) {
    block ->addNumber(lastRead);
    cout << "Poniendo: " << lastRead << endl;
  }
  return  fileState;
}

int InFile::readNumberTo(Block *block) {
  int returnValue = isEOF();
  if (returnValue == OK) {
    char* num = new char [4];
    file.read(num, 4);
    uint32_t number;
    memcpy(&number, num, sizeof(char) * 4);
    delete[] num;
    number = ntohl(number);
    returnValue = isEOF();
    if (returnValue == OK) {
      lastRead = number;
      block -> addNumber(lastRead);
    }
  }
  return returnValue;
}

int InFile::isEOF() {
  int returnValue = OK;
  if (file.eof()) {
    returnValue = END_OF_FILE;
  }
  return returnValue;
}

InFile::~InFile(){
  file.close();
}
