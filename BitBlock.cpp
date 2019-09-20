#include "BitBlock.h"
#include <iostream>
#include <bitset>
#include "OutFile.h"
#include <netinet/in.h>
#include "BitVector.h"
#define MAX_BIT_QUANTITY 32

BitBlock::BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs) {
  if (maxNumb == 0) {
    bitsPerNumb = 0;
  } else {
    bitsPerNumb = calculateBitsPerNumb(maxNumb);
  }
  reference = aReference;
  bitNumbs =  new BitVector(amountOfNumbs * bitsPerNumb);
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

void BitBlock::addNumb(unsigned numbToAdd) {
  bitNumbs -> addBitsFrom(bitsPerNumb, numbToAdd);
}

void BitBlock::writeTo(OutFile* outFile) {
  reference = ntohl(reference);
  outFile -> write((char*) &reference, 4);
  outFile -> write((char*) &bitsPerNumb, 1);
  bitNumbs -> addPadding();
  bitNumbs -> writeTo(outFile);
}

BitBlock::~BitBlock() {
  delete  bitNumbs;
}
