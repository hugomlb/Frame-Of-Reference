#ifndef _BIT_BLOCK_H_
#define _BIT_BLOCK_H_
#include "BitVector.h"
#include "OutFile.h"
class BitBlock {
  private:

    unsigned int bitsPerNumb;
    unsigned int reference;
    int totalBits;
    BitVector* bitNumbs;

    unsigned int calculateBitsPerNumb(unsigned maxNumb);

  public:

    BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs);

    void addNumb(unsigned numbToAdd);

    void writeTo();

    ~BitBlock();

};


#endif
