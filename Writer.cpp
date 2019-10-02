#include "Writer.h"
#define FIRST_QUEUE 0

Writer::Writer(OutFile *outFile, int maxElements, int amountOfQueues) {
  for (int i = 0; i < amountOfQueues; i++){
    vectorOfQueues.emplace_back(maxElements);
  }
  this -> outFile = outFile;
  this -> amountOfQueues = amountOfQueues;
  currentQueue = FIRST_QUEUE;
}

void Writer::write() {
  while (!vectorOfQueues.at(currentQueue).donePoping()) {
    BitBlock bitBlock = std::move(vectorOfQueues.at(currentQueue).pop());
    bitBlock.writeTo(outFile);
    nextQueue();
  }
}

ProtectedBitBlockQueue* Writer::getQueueFor(int thread) {
  return &vectorOfQueues.at(thread);
}

void Writer::nextQueue() {
  unsigned newQueue = currentQueue + 1;
  if (newQueue < vectorOfQueues.size()) {
    currentQueue = newQueue;
  } else {
    currentQueue = FIRST_QUEUE;
  }
}

Writer::~Writer() {
}
