#ifndef _PROTECTED_BLOCK_QUEUE_H_
#define _PROTECTED_BLOCK_QUEUE_H_

#include <queue>
#include <mutex>
#include <condition_variable>
#include "BitBlock.h"
#include "OutFile.h"

class ProtectedBitBlockQueue {
  private:
    std::queue<BitBlock> queue;
    std::mutex m;
    std::condition_variable popCondition;
    std::condition_variable pushCondition;
    unsigned maxElements;
    bool donePushing;
    bool popAvailable;

  public:
    explicit ProtectedBitBlockQueue(int maxAmountOfElements);

  ProtectedBitBlockQueue(const ProtectedBitBlockQueue& other);

    void push(BitBlock bitBlock);

    BitBlock pop();

    bool donePoping();

    void done(bool processState);

    ~ProtectedBitBlockQueue();
};


#endif
