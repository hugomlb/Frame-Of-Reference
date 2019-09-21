#include "ProtectedBlockQueue.h"

ProtectedBlockQueue::ProtectedBlockQueue() {
  maxElements = 5; //NUMERO HARDCODEADO
  donePushing = false;
  popAvailable = false;
}

void ProtectedBlockQueue::push(BitBlock bitBlock, bool processState) {
  //std::unique_lock<std::mutex> lock(m);
  queue.push(bitBlock);
  done(processState);
}

void ProtectedBlockQueue::popTo(OutFile* outFile) {
  /*std::unique_lock<std::mutex> lock(m);
  while (!popAvailable) {
    popCondition.wait(lock);
  }*/
  while (!queue.empty()) {
    queue.front().writeTo(outFile);
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
  //popCondition.notify_all();
}

ProtectedBlockQueue::~ProtectedBlockQueue() {
}
