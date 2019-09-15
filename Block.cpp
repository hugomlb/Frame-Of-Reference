#include "Block.h"
#include <algorithm>
using namespace std;

Block::Block(int amountOfNumbs) {
  minNumb = 0;
  maxNumb = 0;
  numbs.resize(amountOfNumbs);
  iterator = numbs.begin();
}

void Block::addNumber(int numbToAdd) {
  if (iterator < numbs.end()){
    minNumb = min(minNumb, numbToAdd);
    maxNumb = max(maxNumb, numbToAdd);
    *iterator = numbToAdd;
    cout << *iterator << " ";//BORRAR LUEGO
    iterator ++;
  }
}
