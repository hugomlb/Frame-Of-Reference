#ifndef _BITBLOCK_H_
#define _BITBLOCK_H_

#include <vector>
#include <bitset>
class BitBlock {
  private:

    int bitsPerNumb;
    unsigned int reference;
    std::vector<std::bitset<32>>::iterator iterator;
    std::vector<std::bitset<32>> numbsInBits;

    int calculateBitsPerNumb(unsigned  int maxNumb);

  public:

    BitBlock(unsigned  int aReference, unsigned int maxNumb, int amountOfNumbs);

    void addNumb(unsigned int numbToAdd);

    ~BitBlock();

};


#endif
