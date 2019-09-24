#include "Writer.h"
#define FIRST_QUEUE 0

Writer::Writer(OutFile *outFile, int maxElements, int amountOfQueues) {
  for (int i = 0; i < amountOfQueues; i++){
    vectorOfQueue.push_back(ProtectedBlockQueue(maxElements));
  }
  this -> outFile = outFile;
  this -> amountOfQueues = amountOfQueues;
  currentQueue = FIRST_QUEUE;
}

void Writer::write() {
  while (!vectorOfQueue.at(currentQueue).donePoping()) {
    BitBlock bitBlock = std::move(vectorOfQueue.at(currentQueue).pop());
    bitBlock.writeTo(outFile);
    nextQueue();
  }
}

ProtectedBlockQueue* Writer::getQueueFor(int thread) {
  return &vectorOfQueue.at(thread);
}

void Writer::nextQueue() {
  unsigned newQueue = currentQueue + 1;
  if (newQueue < vectorOfQueue.size()) {
    currentQueue = newQueue;
  } else {
    currentQueue = FIRST_QUEUE;
  }
}

Writer::~Writer() {
}
