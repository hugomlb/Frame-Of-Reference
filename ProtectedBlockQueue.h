#ifndef _PROTECTED_BLOCK_QUEUE_H_
#define _PROTECTED_BLOCK_QUEUE_H_

#include <queue>
#include <mutex>
#include <condition_variable>
#include "BitBlock.h"
#include "OutFile.h"

class ProtectedBlockQueue {
  private:
    std::queue<BitBlock> queue;
    std::mutex m;
    std::condition_variable popCondition;
    std::condition_variable pushCondition;
    unsigned maxElements;
    bool donePushing;
    bool popAvailable;

  public:
    explicit ProtectedBlockQueue(int maxAmountOfElements);

    void push(BitBlock bitBlock, bool processState);

    void popTo(OutFile* outFile);

    bool donePoping();

    void done(bool processState);

    ~ProtectedBlockQueue();
};


#endif
