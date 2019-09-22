#ifndef _BIT_BLOCK_H_
#define _BIT_BLOCK_H_
#include "OutFile.h"
#include <vector>
class BitBlock {
  private:
    unsigned int reference;
    std::vector<char>::iterator iterator;
    std::vector<char> bytes;
    char aux;
    int inBit;
    unsigned int bitsPerNumb;

    void nextBit();
    unsigned int calculateBitsPerNumb(unsigned maxNumb);

  public:
    explicit BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs);

    BitBlock(const BitBlock& other) = default;

    BitBlock(BitBlock&& other);

    BitBlock& operator=(const BitBlock& other);

    void addBitsFrom(unsigned numbToAdd);

    void addNumb(unsigned numbToAdd);

    void writeTo(OutFile *outFile);

    void addPadding();

    ~BitBlock();
};
#endif
