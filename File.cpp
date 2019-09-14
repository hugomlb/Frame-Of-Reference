#include "File.h"
#include <iostream>
#include <fstream>
using namespace std;
File::File() {
  this -> file = ifstream ("alot", ios::in|ios::binary);

  if (this -> file.is_open()) {
    this -> file.seekg(0);
    printf("%s\n", "Como andamio");
  } else {
    printf("%s\n", "No se pudo abrir el archivo");
  }
}

File::~File(){
  this -> file.close();
}
