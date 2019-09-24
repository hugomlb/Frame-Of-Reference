#include "ProtectedBlockQueue.h"

ProtectedBlockQueue::ProtectedBlockQueue(int maxAmountOfElements) {
  maxElements = maxAmountOfElements;
  donePushing = false;
  popAvailable = false;
}

ProtectedBlockQueue::ProtectedBlockQueue(const ProtectedBlockQueue &other):
    queue(other.queue) {
  this -> maxElements = other.maxElements;
  this -> donePushing = other.donePushing;
  this -> popAvailable = other.popAvailable;
}

void ProtectedBlockQueue::push(BitBlock bitBlock, bool processState) {
  std::unique_lock<std::mutex> lock(m);
  while (queue.size() >= maxElements) {
    pushCondition.wait(lock);
  }
  queue.push(std::move(bitBlock));
  done(processState);
}

BitBlock ProtectedBlockQueue::pop() {
  std::unique_lock<std::mutex> lock(m);
  BitBlock bitBlock(0, 0, 0);
  while (!popAvailable && !donePushing) {
    popCondition.wait(lock);
  }
  if (queue.size() > 0) {
    bitBlock = std::move(queue.front());
    queue.pop();
    popAvailable = false;
  }
  pushCondition.notify_all();
  return std::move(bitBlock);
}

bool ProtectedBlockQueue::donePoping() {
  bool answer = false;
  if (donePushing && queue.size() == 0) {
    answer = true;
  }
  return  answer;
}

void ProtectedBlockQueue::done(bool processState) {
  popAvailable = true;
  donePushing = processState;
  popCondition.notify_all();
}

ProtectedBlockQueue::~ProtectedBlockQueue() {
}
