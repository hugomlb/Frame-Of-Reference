#ifndef _WRITER_H_
#define _WRITER_H_

#include <vector>
#include "ProtectedBlockQueue.h"
#include "OutFile.h"

class Writer {
private:
  std::vector<ProtectedBlockQueue*> vectorOfQueue;
  OutFile* outFile;
  unsigned currentQueue;
  int amountOfQueues;
public:
  explicit Writer(OutFile* outFile, int maxElements, int amountOfQueues);

  void write();

  ProtectedBlockQueue* getQueueFor(int thread);

  void nextQueue();

  ~Writer();
};


#endif
