#ifndef _BIT_BLOCK_H_
#define _BIT_BLOCK_H_
#include <string>
#include "OutFile.h"
class BitBlock {
  private:

    unsigned int bitsPerNumb;
    unsigned int reference;
    std::string bitNumbs;

    unsigned int calculateBitsPerNumb(unsigned maxNumb);

  public:

    BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs);

    void addNumb(unsigned numbToAdd);

    void writeTo();

    ~BitBlock();

};


#endif
