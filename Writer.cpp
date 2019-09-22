#include "Writer.h"

Writer::Writer(std::vector<ProtectedBlockQueue>* queueVector,
    OutFile *outFile) {
  this -> queues = queueVector;
  this -> outFile = outFile;
  //currentQueue = queues -> begin();
}

void Writer::write() {
  while (!queues -> at(0).donePoping()) {
    queues -> at(0).popTo(outFile);
  }
}
