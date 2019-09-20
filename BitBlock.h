#ifndef _BIT_BLOCK_H_
#define _BIT_BLOCK_H_
#include "BitVector.h"
#include "OutFile.h"
class BitBlock {
  private:
    unsigned int bitsPerNumb;
    unsigned int reference;
    BitVector* bitNumbs;

    unsigned int calculateBitsPerNumb(unsigned maxNumb);

  public:
    explicit BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs);

    void addNumb(unsigned numbToAdd);

    void writeTo(OutFile *outFile);

    ~BitBlock();
};

#endif
