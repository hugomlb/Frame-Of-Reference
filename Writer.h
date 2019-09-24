#ifndef _WRITER_H_
#define _WRITER_H_

#include <vector>
#include "ProtectedBitBlockQueue.h"
#include "OutFile.h"

class Writer {
private:
  std::vector<ProtectedBitBlockQueue> vectorOfQueues;
  OutFile* outFile;
  unsigned currentQueue;
  int amountOfQueues;
public:
  explicit Writer(OutFile* outFile, int maxElements, int amountOfQueues);

  void write();

  ProtectedBitBlockQueue* getQueueFor(int thread);

  void nextQueue();

  ~Writer();
};


#endif
