#ifndef _WRITER_H_
#define _WRITER_H_

#include <vector>
#include "ProtectedBlockQueue.h"
#include "OutFile.h"

class Writer {
  private:
    std::vector<ProtectedBlockQueue> queues;
    unsigned currentQueue;
    OutFile* outFile;

    void toNextQueue();
  public:
    Writer(OutFile* outFile);

    ProtectedBlockQueue* getQueue();

    void write();

    ~Writer();

};


#endif
