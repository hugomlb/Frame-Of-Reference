#ifndef _BLOCK_H_
#define  _BLOCK_H_
#include <vector>

class Block {

  private:

    unsigned int minNumb;
    unsigned int maxNumb;
    std::vector<unsigned int>::iterator iterator;
    std::vector<unsigned int> numbs;

    void updateMax(unsigned int numberAdded);

    void updateMin(unsigned int numberAdded);


  public:

    Block(int amountOfNumbs);

    void addNumber(unsigned int numbToAdd);

    bool hasSpace();

    void subtractMin();

    ~Block();

};
#endif
