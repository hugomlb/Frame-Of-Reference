#include "InFile.h"
#include "FileCompressor.h"

#include <thread>
#include "ProtectedBlockQueue.h"

int main(int argc, char const *argv[]) {
  InFile file(argv[4]);
  OutFile outFile(argv[5]);
  ProtectedBlockQueue queue;
  std::thread lector ([&](){
    FileCompressor fileCompressor(&file, &queue, *argv[1] - '0');
    fileCompressor.compress();
  });
  while (!queue.donePoping()) {
    queue.popTo(&outFile);
  }
  lector.join();

  /*ProtectedBlockQueue queue;
  bool flag = false;
  std::thread producer ([&](){
    for (int i = 0; i < 5; ++i) {
      //std::this_thread::sleep_for(std::chrono::seconds(2));
      if (i == 4) {
        flag = true;
      }
      queue.push(i, flag);
    }
    queue.done(true);
  });

  std::thread consumer ([&](){
    while (!queue.donePoping()) {
      queue.pop();
    }
  });
  producer.join();
  consumer.join();*/
}
