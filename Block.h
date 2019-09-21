#ifndef _BLOCK_H_
#define  _BLOCK_H_
#include <vector>
#include "BitBlock.h"
#include "ProtectedBlockQueue.h"
#include "OutFile.h"

class Block {
  private:
    unsigned minNumb;
    unsigned maxNumb;
    std::vector<unsigned>::iterator iterator;
    std::vector<unsigned> numbs;
    BitBlock* bits;

    void updateMax(unsigned numberAdded);

    void updateMin(unsigned numberAdded);


  public:
    explicit Block(int amountOfNumbs);

    void addNumber(unsigned numbToAdd);

    void reset();

    bool hasSpace();

    BitBlock compressTo(ProtectedBlockQueue* queue);

    ~Block();
};
#endif
