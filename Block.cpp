#include "Block.h"
#include <algorithm>
using namespace std;

Block::Block(int amountOfNumbs) {
  minNumb = 0xffffffff;
  maxNumb = 0;
  numbs.resize(amountOfNumbs);
  iterator = numbs.begin();
}

void Block::addNumber(int numbToAdd) {
  if (iterator < numbs.end()){
    updateMin(numbToAdd);
    updateMax(numbToAdd);
    *iterator = numbToAdd;
    cout << hex << *iterator << endl;//BORRAR LUEGO
    iterator ++;
  }
}

void Block::updateMax(unsigned int numberAdded) {
  if (maxNumb < numberAdded) {
    maxNumb = numberAdded;
  }
}

void Block::updateMin(unsigned int numberAdded) {
  if (minNumb > numberAdded) {
    minNumb = numberAdded;
  }
}

Block::~Block(){
  cout << "Minimo: " << hex << minNumb << endl;
  cout << "Maxima: " << hex << maxNumb << endl;
}
