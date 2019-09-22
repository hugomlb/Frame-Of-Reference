#include "ProtectedBlockQueue.h"

ProtectedBlockQueue::ProtectedBlockQueue(int maxAmountOfElements) {
  maxElements = maxAmountOfElements;
  donePushing = false;
  popAvailable = false;
}

ProtectedBlockQueue::ProtectedBlockQueue(ProtectedBlockQueue &&other) {
  this -> queue = std::move(other.queue);
  this -> maxElements = other.maxElements;
  this -> donePushing = other.donePushing;
  this -> popAvailable = other.popAvailable;
}

ProtectedBlockQueue& ProtectedBlockQueue::operator=(
    const ProtectedBlockQueue & other) {
  if (this == & other) {
    return *this;
  }
  this -> queue = other.queue;
  this -> maxElements = other.maxElements;
  this -> donePushing = other.donePushing;
  this -> popAvailable = other.popAvailable;
  return  *this;
}

void ProtectedBlockQueue::push(BitBlock bitBlock, bool processState) {
  std::unique_lock<std::mutex> lock(m);
  while (queue.size() >= maxElements) {
    pushCondition.wait(lock);
  }
  queue.push(bitBlock);
  done(processState);
}

void ProtectedBlockQueue::popTo(OutFile* outFile) {
  std::unique_lock<std::mutex> lock(m);
  while (!popAvailable) {
    popCondition.wait(lock);
  }
  queue.front().writeTo(outFile);
  queue.pop();
  popAvailable = false;
  pushCondition.notify_all();
}

bool ProtectedBlockQueue::donePoping() {
  bool answer = false;
  if (donePushing && !popAvailable) {
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
