#include "InFile.h"
#include "FileCompressor.h"
#include "OutFile.h"
#include "ProtectedBlockQueue.h"
#include "Writer.h"
#include <vector>
int main(int argc, char const *argv[]) {
  InFile file(argv[4]);
  OutFile outFile(argv[5]);
  int numbsPerBlock = *argv[1] - '0';
  int amountOfThreads = *argv[2] - '0';
  int elementsPerQueue = *argv[3] - '0';
  Writer writer(&outFile, elementsPerQueue, amountOfThreads);
  std::vector<FileCompressor*> threads;
  for (int i = 0; i < (*argv[2] - '0'); i++) {
    threads.push_back(new FileCompressor(&file, writer.getQueueFor(i),
        numbsPerBlock, amountOfThreads, i));
    threads[i] -> start();
  }
  writer.write();
  for (int i = 0; i < (*argv[2] - '0'); i++) {
    threads[i] -> join();
    delete threads[i];
  }
  return 0;
}
