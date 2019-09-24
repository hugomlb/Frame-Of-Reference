#ifndef _BIT_BLOCK_H_
#define _BIT_BLOCK_H_
#include "OutFile.h"
#include <vector>
class BitBlock {
  private:
    unsigned reference;
    std::vector<char>::iterator iterator;
    std::vector<char> bytes;
    char aux;
    int inBit;
    bool validBlock;
    unsigned bitsPerNumb;

    void nextBit();
    unsigned calculateBitsPerNumb(unsigned maxNumb);
    int calculateBytesNeeded(int amountOfNumbs);


  public:
    explicit BitBlock(unsigned aReference, unsigned maxNumb, int amountOfNumbs);

    BitBlock(const BitBlock& other) = default;

    BitBlock(BitBlock&& other);

    BitBlock&operator=(BitBlock&& other);

    void addNumb(unsigned numbToAdd);

    void writeTo(OutFile *outFile);

    void addPadding();

    ~BitBlock();
};
#endif
