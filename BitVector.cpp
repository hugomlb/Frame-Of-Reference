#include "BitVector.h"

#include <iostream>
using namespace std;
#define MAX_BIT_QUANTITY 32

BitVector::BitVector(int amountOfBits) {
  int bytesNeeded = amountOfBits / 8;
  if ((amountOfBits % 8) != 0) {
    bytesNeeded ++;
  }
  bytes.resize(bytesNeeded);
  iterator = bytes.begin();
  inBit = 7;
}

void BitVector::addBitsFrom(int amountOfBits, unsigned numbToAdd) {
  bitset<MAX_BIT_QUANTITY> source(numbToAdd);
  cout << source << endl;
  int i = 1;
  while ( 0 < amountOfBits) {
    aux = (aux &~ (1UL << inBit)) | (source[amountOfBits - 1] << inBit);
    nextBit();
    amountOfBits --;
    cout << "Agrege bits :" << i << endl;
    i++;
  }
}

void BitVector::writeTo(OutFile *outFile) {
  for (iterator = bytes.begin(); iterator < bytes.end(); iterator ++) {
    outFile -> write(&(*iterator), 1);
  }
}

void BitVector::nextBit() {
  if (inBit == 0) {
    inBit = 7;
    *iterator = aux;
    iterator ++;
    bitset<8> bit(aux);
    cout << "Nuevo Numero: " << bit << endl;
  } else {
    inBit --;
  }
}

BitVector::~BitVector() {

}