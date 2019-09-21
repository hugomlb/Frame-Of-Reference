#ifndef _THREAD_H_
#define _THREAD_H_

#include <thread>

class Thread {
  private:
    std::thread thread;

  public:
    Thread();

    Thread(const Thread&) = delete;

    Thread& operator=(const Thread&) = delete;

    Thread(Thread&& other);

    Thread& operator=(Thread &&other);

    virtual void run() = 0;

    void start();

    void join();

    virtual ~Thread();
};


#endif
