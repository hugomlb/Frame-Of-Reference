#include "BitBlock.h"
#include <iostream>
#include <bitset>
using namespace std;
#define MAX_BIT_QUANTITY 32

BitBlock::BitBlock(unsigned int aReference, unsigned int maxNumb, int amountOfNumbs) {
  bitsPerNumb = calculateBitsPerNumb(maxNumb);
  reference = aReference;
  bitNumbs.resize(bitsPerNumb * amountOfNumbs);
}

unsigned int BitBlock::calculateBitsPerNumb(unsigned int maxNumb) {
  bitset<MAX_BIT_QUANTITY>  bits (maxNumb);
  int inBit = 0;
  unsigned int index = MAX_BIT_QUANTITY;
  while (inBit == 0 && index > 0) {
    index --;
    inBit = bits[index];
  }
  index ++;
  return index;
}

void BitBlock::addNumb(unsigned int numbToAdd) {
  bitset<MAX_BIT_QUANTITY>  bitNumber(numbToAdd);
  cout << bitNumber << endl;
  string auxString = bitNumber.to_string();
  bitNumbs.append(auxString, 20);
  cout << "String: " << bitNumbs << endl;
}

void BitBlock::writeTo(OutFile *outFile) {

}

BitBlock::~BitBlock() {

}