#ifndef _BLOCK_H_
#define  _BLOCK_H_

#include <vector>

class Block {

  private:

    int min;
    int max;
    std::vector<int>::iterator iterator;
    std::vector<int> numbs;

  public:

    Block(int amountOfNumbs);

    void addNumber(int numbToAdd);

    ~Block();

};
#endif
