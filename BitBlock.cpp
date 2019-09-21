#include "BitBlock.h"
#include <iostream>
#include <bitset>
#include "OutFile.h"
#include <netinet/in.h>
#include <bitset>
#define MAX_BIT_QUANTITY 32

BitBlock::BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs) {
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
  reference = aReference;
}

unsigned int BitBlock::calculateBitsPerNumb(unsigned maxNumb) {
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

void BitBlock::addBitsFrom(unsigned numbToAdd) {
  std::bitset<MAX_BIT_QUANTITY> source(numbToAdd);
  int amountOfBits = bitsPerNumb;
  while (0 < amountOfBits) {
    aux = (aux &~ (1UL << inBit)) | (source[amountOfBits - 1] << inBit);
    nextBit();
    amountOfBits --;
  }
}

void BitBlock::addNumb(unsigned numbToAdd) {
  addBitsFrom(numbToAdd);
}

void BitBlock::writeTo(OutFile* outFile) {
  reference = ntohl(reference);
  outFile -> write((char*) &reference, 4);
  addPadding();
  outFile -> write((char*) &bitsPerNumb, 1);
  for (iterator = bytes.begin(); iterator < bytes.end(); iterator ++) {
    outFile -> write(&(*iterator), 1);
  }
}

void BitBlock::addPadding() {
  if (iterator != bytes.end() && inBit != 7) {
    while  (inBit >= 0) {
      aux = (aux &~ (1UL << inBit)) | (0 << inBit);
      inBit --;
    }
    *iterator = aux;
  }
}

void BitBlock::nextBit() {
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

BitBlock::~BitBlock() {
}
