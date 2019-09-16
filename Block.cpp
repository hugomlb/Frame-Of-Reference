#include "Block.h"
#include <algorithm>
#include <iostream>
#include "BitBlock.h"
using namespace std;
#define MIN_VALUE 0
#define MAX_VALUE 0xffffffff


Block::Block(int amountOfNumbs) {
  numbs.resize(amountOfNumbs);
  reset();
}

void Block::addNumber(unsigned numbToAdd) {
  if (iterator < numbs.end()){
    updateMin(numbToAdd);
    updateMax(numbToAdd);
    *iterator = numbToAdd;
    iterator ++;
  }
}

void Block::updateMax(unsigned numberAdded) {
  if (maxNumb < numberAdded) {
    maxNumb = numberAdded;
  }
}

void Block::updateMin(unsigned numberAdded) {
  if (minNumb > numberAdded) {
    minNumb = numberAdded;
  }
}
void Block::reset() {
  iterator = numbs.begin();
  minNumb = MAX_VALUE;
  maxNumb = MIN_VALUE;
}

bool Block::hasSpace() {
  bool answer = false;
  if (iterator < numbs.end()) {
    answer = true;
  }
  return answer;
}

void Block::subtractMin() {
  cout << "Min: " << hex << minNumb << endl;
  cout << "Max: " << hex << maxNumb << endl;
  BitBlock bits(minNumb, maxNumb, 4);
  for (iterator = numbs.begin(); iterator < numbs.end(); iterator ++) {
    bits.addNumb(*iterator - minNumb);
  }

  bits.writeTo();
}

Block::~Block() {

}
