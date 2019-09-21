#include "Writer.h"

Writer::Writer(ProtectedBlockQueue* queue, OutFile *outFile) {
  this -> queue = queue;
  this -> outFile = outFile;
}

void Writer::write() {
  while (!queue -> donePoping()) {
    queue -> popTo(outFile);
  }
}
