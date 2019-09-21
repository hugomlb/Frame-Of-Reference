#ifndef _WRITER_H_
#define _WRITER_H_

#include <vector>
#include "ProtectedBlockQueue.h"
#include "OutFile.h"

class Writer {
  private:
    ProtectedBlockQueue* queue;
    OutFile* outFile;
  public:
    Writer(ProtectedBlockQueue* queue, OutFile* outFile);

    void write();

};


#endif
