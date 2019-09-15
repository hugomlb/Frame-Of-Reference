#include "Block.h"
using namespace std;

Block::Block(int amountOfNumbs) {
  min = 0;
  max = 0;
  numbs.resize(amountOfNumbs);
  iterator = numbs.begin();
}

void Block::addNumber(int numbToAdd) {

}
