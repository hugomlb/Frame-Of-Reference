#include "Reader.h"
#include <iostream>
#include <fstream>
using namespace std;

Reader::Reader() {
  ifstream file("alot", ios::in|ios::binary);

  if (file.is_open()) {
    unsigned char* memblock = new unsigned char[1];
    file.read((char*) memblock, 1);
    printf("%x\n", *memblock);
    file.close();
  } else {
    printf("%s\n", "NEL");
  }
}

Reader::~Reader() {

}
