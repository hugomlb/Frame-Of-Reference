#include "BitBlock.h"
#include <iostream>
#include <bitset>
using namespace std;
#define MAX_BIT_QUANTITY 32

BitBlock::BitBlock(unsigned int aReference, unsigned int maxNumb) {
  calculateBitsPerNumb(maxNumb);
}

void BitBlock::calculateBitsPerNumb(unsigned int maxNumb) {
  bitset<MAX_BIT_QUANTITY>  bits (maxNumb);
  int inBit = 0;
  bitsPerNumb = MAX_BIT_QUANTITY;
  while (inBit == 0 && bitsPerNumb > 0) {
    bitsPerNumb --;
    inBit = bits[bitsPerNumb];
  }
  cout << bitsPerNumb << endl;
}

BitBlock::~BitBlock() {

}