#include "BitVector.h"
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
  std::bitset<MAX_BIT_QUANTITY> source(numbToAdd);
  while (0 < amountOfBits) {
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

void BitVector::addPadding() {
  if (iterator != bytes.end() && inBit != 7) {
    while  (inBit >= 0) {
      aux = (aux &~ (1UL << inBit)) | (0 << inBit);
      inBit --;
    }
    *iterator = aux;
  }
}

void BitVector::nextBit() {
  if (inBit == 0) {
    inBit = 7;
    if (iterator !=  bytes.end()){
      *iterator = aux;
      iterator ++;
    }
  } else {
    inBit --;
  }
}

BitVector::~BitVector() {
}
