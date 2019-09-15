#include "File.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#include <netinet/in.h>
using namespace std;
#define END_OF_FILE -1

File::File() {
  this -> file = ifstream ("alot", ios::in|ios::binary);
  if (this -> file.is_open()) {
    this -> file.seekg(0);
  } else {
    printf("%s\n", "No se pudo abrir el archivo");
  }
}
// FUNCION DE MAS DE 15 LINEAS *********************************************
int File::readNumber() {
  int returnValue = 0;
  if (this -> file.eof()) {
    returnValue = END_OF_FILE;
  } else {
    char* num = new char [4];
    file.read(num, 4);
    uint32_t number;
    memcpy(&number, num, sizeof(char) * 4);
    number = ntohl(number);
    if (file.eof()) {
      returnValue = END_OF_FILE;
    } else {
      returnValue = number;
    }
  }
  return returnValue;
}

File::~File(){
  this -> file.close();
}
