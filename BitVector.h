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
  unsigned int bitsPerNumb;

  void nextBit();
  unsigned int calculateBitsPerNumb(unsigned maxNumb);

  public:
  explicit BitVector(unsigned maxNumb, int amountOfNumbs);

  void addBitsFrom(unsigned numbToAdd);

  void writeTo(OutFile* outFile);

  void addPadding();

  ~BitVector();
};


#endif
