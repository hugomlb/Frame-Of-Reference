#include "BitBlock.h"
#include <bitset>
#include "OutFile.h"
#include <netinet/in.h>
#define MAX_BIT_QUANTITY 32
#define FIRST_BIT 7
#define LAST_BIT 0
#define REFERENCE_SIZE 4

BitBlock::BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs) {
  bitsPerNumb = calculateBitsPerNumb(maxNumb);
  bytes.resize(calculateBytesNeeded(amountOfNumbs));
  iterator = bytes.begin();
  inBit = FIRST_BIT;
  reference = aReference;
  validBlock = true;
  if (amountOfNumbs == 0) {
    validBlock = false;
  }
}

BitBlock::BitBlock(BitBlock &&other): iterator(std::move(other.iterator)),
    bytes(std::move(other.bytes)) {
  this -> reference = other.reference;
  this -> aux = other.aux;
  this -> bitsPerNumb = other.bitsPerNumb;
  this -> inBit = other.inBit;
  this -> validBlock = other.validBlock;
}

BitBlock& BitBlock::operator=(BitBlock &&other) {
  if (this == &other) {
    return  *this;
  }
  this -> iterator = std::move(other.iterator);
  this -> bytes = std::move(other.bytes);
  this -> reference = other.reference;
  this -> aux = other.aux;
  this -> bitsPerNumb = other.bitsPerNumb;
  this -> inBit = other.inBit;
  this -> validBlock = other.validBlock;
  return *this;
}

int BitBlock::calculateBytesNeeded(int amountOfNumbs) {
  int amountOfBits = amountOfNumbs * bitsPerNumb;
  int bytesNeeded = amountOfBits / 8;
  if ((amountOfBits % 8) != 0) {
    bytesNeeded ++;
  }
  return bytesNeeded;
}

unsigned int BitBlock::calculateBitsPerNumb(unsigned maxNumb) {
  std::bitset<MAX_BIT_QUANTITY>  bits(maxNumb);
  int inBit = 0;
  unsigned index = MAX_BIT_QUANTITY;
  if (maxNumb != 0) {
    while (inBit == 0 && index > 0) {
      index --;
      inBit = bits[index];
    }
    index ++;
  } else {
    index = 0;
  }
  return index;
}

void BitBlock::addNumb(unsigned numbToAdd) {
  std::bitset<MAX_BIT_QUANTITY> source(numbToAdd);
  int amountOfBits = bitsPerNumb;
  while (0 < amountOfBits) {
    aux = (aux &~ (1UL << inBit)) | (source[amountOfBits - 1] << inBit);
    nextBit();
    amountOfBits --;
  }
}

void BitBlock::writeTo(OutFile* outFile) {
  if (validBlock) {
    reference = htobe32(reference);
    outFile -> write((char*) &reference, REFERENCE_SIZE);
    outFile -> write((char*) &bitsPerNumb, 1);
    for (iterator = bytes.begin(); iterator < bytes.end(); iterator ++) {
      outFile -> write(&(*iterator), 1);
    }
  }
}

void BitBlock::addPadding() {
  if (iterator != bytes.end() && inBit != FIRST_BIT) {
    while  (inBit >= 0) {
      aux = (aux &~ (1UL << inBit)) | (0 << inBit);
      inBit --;
    }
    *iterator = aux;
  }
}

void BitBlock::nextBit() {
  if (inBit == LAST_BIT) {
    inBit = FIRST_BIT;
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
