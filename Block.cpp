#include "Block.h"
#include <algorithm>
#include <iostream>
#include "BitBlock.h"
using namespace std;
#define MIN_VALUE 0
#define MAX_VALUE 0xffffffff


Block::Block(int amountOfNumbs) {
  minNumb = MAX_VALUE;
  maxNumb = MIN_VALUE;
  numbs.resize(amountOfNumbs);
  iterator = numbs.begin();
}

void Block::addNumber(unsigned int numbToAdd) {
  if (iterator < numbs.end()){
    updateMin(numbToAdd);
    updateMax(numbToAdd);
    *iterator = numbToAdd;
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

bool Block::hasSpace() {
  bool answer = false;
  if (iterator < numbs.end()) {
    answer = true;
  }
  return answer;
}

void Block::sustractMin() {
  maxNumb = maxNumb - minNumb;
  for (iterator = numbs.begin(); iterator < numbs.end(); iterator ++) {
    *iterator = *iterator - minNumb;
  }
  BitBlock bits(minNumb, maxNumb, 4);
  bits.addNumb(numbs[0]);
  bits.addNumb(numbs[1]);
  bits.addNumb(numbs[2]);
  bits.addNumb(numbs[3]);
}

Block::~Block() {

}
