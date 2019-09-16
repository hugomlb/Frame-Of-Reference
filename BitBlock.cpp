#include "BitBlock.h"
#include <iostream>
#include <string>
using namespace std;
#define MAX_BIT_QUANTITY 32

BitBlock::BitBlock(unsigned int aReference, unsigned int maxNumb, int amountOfNumbs) {
  bitsPerNumb = calculateBitsPerNumb(maxNumb);
  reference = aReference;

}

int BitBlock::calculateBitsPerNumb(unsigned int maxNumb) {
  bitset<MAX_BIT_QUANTITY>  bits (maxNumb);
  int inBit = 0;
  int index = MAX_BIT_QUANTITY;
  while (inBit == 0 && index > 0) {
    index --;
    inBit = bits[index];
  }
  index ++;
  return index;
}

void BitBlock::addNumb(unsigned int numbToAdd) {
  cout << hex << numbToAdd << endl;
  bitset<MAX_BIT_QUANTITY> bitNumb(numbToAdd);

}

BitBlock::~BitBlock() {

}