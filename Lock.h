#ifndef TP2_LOCK_H
#define TP2_LOCK_H

#include <mutex>

class Lock {
  private:
    std::mutex& mutex;
  public:
    explicit Lock(std::mutex& aMutex);

    ~Lock();

};
#endif
