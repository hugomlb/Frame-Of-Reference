#include "BitBlock.h"
#include <iostream>
#include <bitset>
using namespace std;
#define MAX_BIT_QUANTITY 32

BitBlock::BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs) {
  bitsPerNumb = calculateBitsPerNumb(maxNumb);
  reference = aReference;
  bitNumbs.resize(bitsPerNumb * amountOfNumbs);
}

unsigned int BitBlock::calculateBitsPerNumb(unsigned maxNumb) {
  bitset<MAX_BIT_QUANTITY>  bits (maxNumb);
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
  bitset<MAX_BIT_QUANTITY>  bitNumber(numbToAdd);
  cout << bitNumber << endl;
  string auxString = bitNumber.to_string();
  bitNumbs.append(auxString, MAX_BIT_QUANTITY - (int) bitsPerNumb);
  cout << "String: " << bitNumbs << endl;
}

void BitBlock::writeTo(OutFile *outFile) {

}

BitBlock::~BitBlock() {

}