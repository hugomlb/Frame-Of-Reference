#include "BitVector.h"
#define MAX_BIT_QUANTITY 32

#include <bitset>

BitVector::BitVector(unsigned maxNumb, int amountOfNumbs) {
  if (maxNumb == 0) {
    bitsPerNumb = 0;
  } else {
    bitsPerNumb = calculateBitsPerNumb(maxNumb);
  }
  int amountOfBits = amountOfNumbs * bitsPerNumb;
  int bytesNeeded = amountOfBits / 8;
  if ((amountOfBits % 8) != 0) {
    bytesNeeded ++;
  }
  bytes.resize(bytesNeeded);
  iterator = bytes.begin();
  inBit = 7;
}

unsigned int BitVector::calculateBitsPerNumb(unsigned maxNumb) {
  std::bitset<MAX_BIT_QUANTITY>  bits(maxNumb);
  int inBit = 0;
  unsigned index = MAX_BIT_QUANTITY;
  while (inBit == 0 && index > 0) {
    index --;
    inBit = bits[index];
  }
  index ++;
  return index;
}

void BitVector::addBitsFrom(unsigned numbToAdd) {
  std::bitset<MAX_BIT_QUANTITY> source(numbToAdd);
  int amountOfBits = bitsPerNumb;
  while (0 < amountOfBits) {
    aux = (aux &~ (1UL << inBit)) | (source[amountOfBits - 1] << inBit);
    nextBit();
    amountOfBits --;
  }
}

void BitVector::writeTo(OutFile *outFile) {
  outFile -> write((char*) &bitsPerNumb, 1);
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
