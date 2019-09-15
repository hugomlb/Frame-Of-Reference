#ifndef _BLOCK_H_
#define  _BLOCK_H_
#include <iostream> //BORRAR CON PRINTF
#include <vector>

class Block {

  private:

    unsigned int minNumb;
    unsigned int maxNumb;
    std::vector<int>::iterator iterator;
    std::vector<int> numbs;

    void updateMax(unsigned int numberAdded);

    void updateMin(unsigned int numberAdded);

  public:

    Block(int amountOfNumbs);

    void addNumber(int numbToAdd);

    ~Block();

};
#endif
