#include "Writer.h"

Writer::Writer(std::vector<ProtectedBlockQueue>* queueVector,
    OutFile *outFile) {
  this -> vectorOfQueue = queueVector;
  this -> outFile = outFile;
  currentQueue = 0;
}

void Writer::write() {
  while (!vectorOfQueue -> at(currentQueue).donePoping()) {
    vectorOfQueue -> at(currentQueue).popTo(outFile);
    nextQueue();
  }
}

void Writer::nextQueue() {
  unsigned newQueue = currentQueue + 1;
  if (newQueue < vectorOfQueue -> size()) {
    currentQueue = newQueue;
  } else {
    currentQueue = 0;
  }
}
