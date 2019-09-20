#ifndef _BIT_BLOCK_H_
#define _BIT_BLOCK_H_
#include "BitVector.h"
#include "OutFile.h"
class BitBlock {
  private:
    unsigned int reference;
    BitVector bitNumbs;

  public:
    explicit BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs);

    //explicit BitBlock(BitBlock&& other);

    void addNumb(unsigned numbToAdd);

    void writeTo(OutFile *outFile);

    ~BitBlock();
};

#endif
