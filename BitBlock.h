#ifndef _BIT_BLOCK_H_
#define _BIT_BLOCK_H_
#include <string>
#include "OutFile.h"
class BitBlock {
  private:

    unsigned int bitsPerNumb;
    unsigned int reference;
    std::string bitNumbs;

    unsigned int calculateBitsPerNumb(unsigned  int maxNumb);

  public:

    BitBlock(unsigned  int aReference, unsigned int maxNumb, int amountOfNumbs);

    void addNumb(unsigned int numbToAdd);

    void writeTo(OutFile* outFile);

    ~BitBlock();

};


#endif
