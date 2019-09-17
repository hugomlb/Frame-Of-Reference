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
  inBit = 0;
}

void BitVector::addBitsFrom(int amountOfBits, unsigned numbToAdd) {
  /*bitset<MAX_BIT_QUANTITY> source(numbToAdd);
  int bitsAdded = 0;
  while (bitsAdded < amountOfBits) {
    while (inBit < 8) {
      *iterator = (*iterator &~ (1UL << inBit)) | (source[bitsAdded] << inBit);
      inBit ++;
      bitsAdded ++;
    }
    iterator ++;
    inBit = 0;
  }*/
}

void BitVector::writeTo(OutFile *outFile) {
  for (iterator = bytes.begin(); iterator < bytes.end(); iterator ++) {
    outFile -> write(&(*iterator), 1);
  }
}

BitVector::~BitVector() {

}