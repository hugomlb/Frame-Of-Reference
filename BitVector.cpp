#include "BitVector.h"
using namespace std;
#define MAX_BIT_QUANTITY 32

#include <bitset>

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
  while ( 0 < amountOfBits) {
    aux = (aux &~ (1UL << inBit)) | (source[amountOfBits - 1] << inBit);
    nextBit();
    amountOfBits --;
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
  } else {
    inBit --;
  }
}

BitVector::~BitVector() {
}