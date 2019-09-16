#ifndef _BITBLOCK_H_
#define _BITBLOCK_H_

#include <bitset>
#include <vector>

class BitBlock {
  private:

    std::vector<unsigned int> numbs;
    int bitsPerNumb;
    unsigned int reference;


    int calculateBitsPerNumb(unsigned  int maxNumb);

  public:

    BitBlock(unsigned  int aReference, unsigned int maxNumb, int amountOfNumbs);

    void addNumb(unsigned int numbToAdd);

    ~BitBlock();

};


#endif
