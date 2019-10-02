#include "ProtectedBitBlockQueue.h"
#include "Lock.h"

ProtectedBitBlockQueue::ProtectedBitBlockQueue(int maxAmountOfElements) {
  maxElements = maxAmountOfElements;
  donePushing = false;
  popAvailable = false;
}

ProtectedBitBlockQueue::ProtectedBitBlockQueue
  (const ProtectedBitBlockQueue &other):queue(other.queue) {
  this -> maxElements = other.maxElements;
  this -> donePushing = other.donePushing;
  this -> popAvailable = other.popAvailable;
}

void ProtectedBitBlockQueue::push(BitBlock bitBlock) {
  std::unique_lock<std::mutex> lock(m);
  while (queue.size() >= maxElements) {
    pushCondition.wait(lock);
  }
  queue.push(std::move(bitBlock));
  done(false);
}

BitBlock ProtectedBitBlockQueue::pop() {
  std::unique_lock<std::mutex> lock(m);
  BitBlock bitBlock(0, 0, 0);
  while (!popAvailable && !donePushing) {
    popCondition.wait(lock);
  }
  if (!queue.empty()) {
    bitBlock = std::move(queue.front());
    queue.pop();
    popAvailable = false;
  }
  pushCondition.notify_all();
  return std::move(bitBlock);
}

bool ProtectedBitBlockQueue::donePoping() {
  bool answer = false;
  if (donePushing && queue.size() == 0) {
    answer = true;
  }
  return  answer;
}

void ProtectedBitBlockQueue::done(bool processState) {
  popAvailable = true;
  donePushing = processState;
  popCondition.notify_all();
}

ProtectedBitBlockQueue::~ProtectedBitBlockQueue() {
}
