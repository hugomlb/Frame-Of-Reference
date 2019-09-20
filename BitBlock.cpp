#include "BitBlock.h"
#include <iostream>
#include <bitset>
#include "OutFile.h"
#include <netinet/in.h>
#include "BitVector.h"
#define MAX_BIT_QUANTITY 32

BitBlock::BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs)
                    :bitNumbs(maxNumb, amountOfNumbs) {
  reference = aReference;
}

void BitBlock::addNumb(unsigned numbToAdd) {
  bitNumbs.addBitsFrom(numbToAdd);
}

void BitBlock::writeTo(OutFile* outFile) {
  reference = ntohl(reference);
  outFile -> write((char*) &reference, 4);
  bitNumbs.addPadding();
  bitNumbs.writeTo(outFile);
}

BitBlock::~BitBlock() {
}
