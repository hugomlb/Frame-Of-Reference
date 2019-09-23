#include "Lock.h"

Lock::Lock(std::mutex &aMutex) :mutex(aMutex) {
  mutex.lock();
}

Lock::~Lock() {
  mutex.unlock();
}
