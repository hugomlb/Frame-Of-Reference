#ifndef _WRITER_H_
#define _WRITER_H_

#include <vector>
#include "ProtectedBlockQueue.h"
#include "OutFile.h"

class Writer {
  private:
    std::vector<ProtectedBlockQueue>* queues;
    //std::vector<ProtectedBlockQueue*>:: iterator currentQueue;
    OutFile* outFile;
  public:
    Writer(std::vector<ProtectedBlockQueue>* queueVector, OutFile* outFile);

    void write();

};


#endif
