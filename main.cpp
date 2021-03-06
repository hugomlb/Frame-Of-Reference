#include "ProtectedInFile.h"
#include "FileCompressor.h"
#include "OutFile.h"
#include "Writer.h"
#include <vector>
int main(int argc, char const *argv[]) {
  ProtectedInFile file(argv[4]);
  OutFile outFile(argv[5]);
  int numbsPerBlock = std::stoi(argv[1]);
  int amountOfThreads = std::stoi(argv[2]);
  int elementsPerQueue = std::stoi(argv[3]);
  Writer writer(&outFile, elementsPerQueue, amountOfThreads);
  std::vector<FileCompressor*> threads;
  for (int i = 0; i < amountOfThreads; i++) {
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
