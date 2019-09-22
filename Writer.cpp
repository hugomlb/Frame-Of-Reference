#include "Writer.h"

Writer::Writer(OutFile *outFile) {
  queues.push_back(ProtectedBlockQueue(5));
  this -> outFile = outFile;
  currentQueue = 0;
}

void Writer::write() {
  while (!queues.at(currentQueue).donePoping()) {
    queues.at(currentQueue).popTo(outFile);
    //toNextQueue();
  }
}

ProtectedBlockQueue* Writer::getQueue() {
  return &queues[0];
}

void Writer::toNextQueue() {
  if (queues.at(currentQueue).donePoping()) {
    queues.erase(queues.begin() + currentQueue);
  } else if ((currentQueue + 1) == queues.size()) {
    currentQueue = 0;
  }else {
    currentQueue ++;
  }
}

Writer::~Writer() {
}
