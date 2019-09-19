#ifndef _BIT_VECTOR_H_
#define _BIT_VECTOR_H_

#include <vector>
#include "OutFile.h"

class BitVector {
  private:
  std::vector<char>::iterator iterator;
  std::vector<char> bytes;
  char aux;
  int inBit;
  void nextBit();

  public:
  BitVector(int amountOfBits);

  void addBitsFrom(int amountOfBits, unsigned numbToAdd);

  void writeTo(OutFile* outFile);

  void addPadding();

  ~BitVector();
};


#endif
