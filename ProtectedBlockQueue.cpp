#include "ProtectedBlockQueue.h"

ProtectedBlockQueue::ProtectedBlockQueue(int maxAmountOfElements) {
  maxElements = maxAmountOfElements;
  donePushing = false;
  popAvailable = false;
  popFinish = false;
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
  BitBlock bitBlock(0, 0, 0); //chequear lo que dijo Matias **********************
  while (!popAvailable && !popFinish) {
    popCondition.wait(lock);
  }
  if (queue.size() > 0) {
    bitBlock = std::move(queue.front());
    queue.pop();
    popAvailable = false;
  }
  if (donePushing && queue.size() == 0){
    popFinish = true;
  }
  pushCondition.notify_all();
  return std::move(bitBlock);
}

bool ProtectedBlockQueue::donePoping() {
/*  bool answer = false;
  if (donePushing && !popAvailable) {
    answer = true;
  }*/
  return  popFinish;
}

void ProtectedBlockQueue::done(bool processState) {
  popAvailable = true;
  donePushing = processState;
  popCondition.notify_all();
}

ProtectedBlockQueue::~ProtectedBlockQueue() {
}
