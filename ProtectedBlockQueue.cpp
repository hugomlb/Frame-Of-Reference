#include "ProtectedBlockQueue.h"

ProtectedBlockQueue::ProtectedBlockQueue() {
  maxElements = 5; //NUMERO HARDCODEADO
  donePushing = false;
  popAvailable = false;
}

void ProtectedBlockQueue::push(BitBlock bitBlock, bool processState) {
  std::unique_lock<std::mutex> lock(m);
  while (queue.size() >= maxElements) {
    pushCondition.wait(lock);
  }
  queue.push(bitBlock);
  std::cout << "Push, Hay" << queue.size() << std::endl;
  done(processState);
}

void ProtectedBlockQueue::popTo(OutFile* outFile) {
  std::unique_lock<std::mutex> lock(m);
  while (!popAvailable) {
    popCondition.wait(lock);
  }
  while (!queue.empty()) {
    queue.front().writeTo(outFile);
    queue.pop();
    std::cout << "Pop, Quedan: " << queue.size() << std::endl;
  }
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
