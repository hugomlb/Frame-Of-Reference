#include "InFile.h"
#include "FileCompressor.h"

#include <thread>
#include "ProtectedBlockQueue.h"

int main(int argc, char const *argv[]) {
  InFile file(argv[4]);
  OutFile outFile(argv[5]);
  FileCompressor fileCompressor(&file, &outFile, *argv[1] - '0');
  fileCompressor.compress();
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
