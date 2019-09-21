#include "InFile.h"
#include "FileCompressor.h"

#include <thread>
#include "ProtectedBlockQueue.h"

int main(int argc, char const *argv[]) {
  InFile file(argv[4]);
  OutFile outFile(argv[5]);
  ProtectedBlockQueue queue(*argv[3] - '0');
  std::thread lector([&](){
    FileCompressor fileCompressor(&file, &queue, *argv[1] - '0');
    fileCompressor.compress();
  });
  while (!queue.donePoping()) {
    queue.popTo(&outFile);
  }
  lector.join();
}
