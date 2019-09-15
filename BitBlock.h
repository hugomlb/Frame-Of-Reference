#ifndef _BITBLOCK_H_
#define _BITBLOCK_H_


class BitBlock {
  private:

    int bitsPerNumb;
    unsigned int reference;

    void calculateBitsPerNumb(unsigned  int maxNumb);


  public:
    BitBlock(unsigned  int aReference, unsigned int maxNumb);

    ~BitBlock();

};


#endif
