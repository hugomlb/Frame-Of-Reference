#include "Block.h"
#include "BitBlock.h"
#define MIN_VALUE 0
#define MAX_VALUE 0xffffffff

void Block::test() {
  std::cout << "Poppeando" << std::endl;
}

void Block::testpush() {
  std::cout << "Pusheando" << std::endl;
}

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

void Block::compress() {
  bits =  new BitBlock(minNumb, (maxNumb - minNumb), numbs.size());
  for (iterator = numbs.begin(); iterator < numbs.end(); iterator ++) {
    bits -> addNumb(*iterator - minNumb);
  }
}

void Block::writeTo(OutFile *outFile) {
  bits -> writeTo(outFile);
  delete bits;
}

Block::~Block() {
}
