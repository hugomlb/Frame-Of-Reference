#ifndef _BLOCK_H_
#define  _BLOCK_H_
#include <vector>

class Block {

  private:

    unsigned minNumb;
    unsigned maxNumb;
    std::vector<unsigned>::iterator iterator;
    std::vector<unsigned> numbs;

    void updateMax(unsigned numberAdded);

    void updateMin(unsigned numberAdded);


  public:

    Block(int amountOfNumbs);

    void addNumber(unsigned numbToAdd);

    void reset();

    bool hasSpace();

    void subtractMin();

    ~Block();

};
#endif
