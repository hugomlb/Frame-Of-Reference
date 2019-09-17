#ifndef _BIT_VECTOR_H_
#define _BIT_VECTOR_H_

#include <vector>
#include <bitset>
#include "OutFile.h"

class BitVector {
  private:

  std::vector<char>::iterator iterator;
  std::vector<char> bytes;
  int inBit;

  public:

  BitVector(int amountOfBits);

  void addBitsFrom(int amountOfBits, unsigned numbToAdd);

  void writeTo(OutFile* outFile);

  ~BitVector();
};


#endif
