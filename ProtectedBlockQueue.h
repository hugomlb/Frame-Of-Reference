#ifndef _PROTECTED_BLOCK_QUEUE_H_
#define _PROTECTED_BLOCK_QUEUE_H_

#include <queue>
#include <mutex>
#include <condition_variable>
#include "Block.h"

class ProtectedBlockQueue {
  private:
    std::queue<Block> queue;
    std::mutex m;
    std::condition_variable popCondition;
    int maxElements;
    bool donePushing;
    bool popAvailable;

  public:
    ProtectedBlockQueue();

    void push(Block block, bool processState);

    void pop();

    bool donePoping();

    void done(bool processState);

    ~ProtectedBlockQueue();
};


#endif
