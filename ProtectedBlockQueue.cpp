#include "ProtectedBlockQueue.h"

ProtectedBlockQueue::ProtectedBlockQueue() {
  maxElements = 5; //NUMERO HARDCODEADO
  donePushing = false;
  popAvailable = false;
}

void ProtectedBlockQueue::push(Block block, bool processState) {
  std::unique_lock<std::mutex> lock(m);
  queue.push(block);
  done(processState);
}

void ProtectedBlockQueue::pop() {
  std::unique_lock<std::mutex> lock(m);
  while (!popAvailable) {
    popCondition.wait(lock);
  }
  while (!queue.empty()) {
    //Block aBlock = queue.front();
    queue.pop();
  }
  popAvailable = false;
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
