#ifndef _BLOCK_H_
#define  _BLOCK_H_
#include <iostream> //BORRAR CON PRINTF
#include <vector>

class Block {

  private:

    int minNumb;
    int maxNumb;
    std::vector<int>::iterator iterator;
    std::vector<int> numbs;

  public:

    Block(int amountOfNumbs);

    void addNumber(int numbToAdd);

    ~Block();

};
#endif
