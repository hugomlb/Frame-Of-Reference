#include "Writer.h"

Writer::Writer(std::vector<ProtectedBlockQueue>* queueVector,
    OutFile *outFile) {
  this -> queues = queueVector;
  this -> outFile = outFile;
  currentQueue = 0;
}

void Writer::write() {
  while (!queues -> empty()) {
    queues -> at(currentQueue).popTo(outFile);
    toNextQueue();
  }
}

void Writer::toNextQueue() {
  if (queues -> at(currentQueue).donePoping()) {
    queues -> erase(queues -> begin() + currentQueue);
  } else if (currentQueue + 1 == queues -> size()) {
    currentQueue = 0;
  }else {
    currentQueue ++;
  }
}

