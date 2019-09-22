#ifndef _WRITER_H_
#define _WRITER_H_

#include <vector>
#include "ProtectedBlockQueue.h"
#include "OutFile.h"

class Writer {
  private:
    std::vector<ProtectedBlockQueue>* vectorOfQueue;
    OutFile* outFile;
    unsigned currentQueue;
  public:
    Writer(std::vector<ProtectedBlockQueue>* queueVector, OutFile* outFile);

    void write();

    bool nextQueue();
};


#endif
