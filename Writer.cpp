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

bool Writer::nextQueue() {
  unsigned newQueue = currentQueue + 1;
  bool notFound = false;
  bool found = false;
  bool endReached = false;
  do {
    if (newQueue < vectorOfQueue -> size()) {
      if (!vectorOfQueue -> at(newQueue).donePoping()) {
        found = true;
      } else {
        newQueue ++;
      }
    } else {
      if (endReached) {
        notFound = true;
      } else {
        endReached = true;
        newQueue = 0;
      }
    }
  } while (!notFound && !found);
  return false;
}
