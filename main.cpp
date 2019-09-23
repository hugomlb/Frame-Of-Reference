#include "InFile.h"
#include "FileCompressor.h"
#include "OutFile.h"
#include "ProtectedBlockQueue.h"
#include "Writer.h"

int main(int argc, char const *argv[]) {
  InFile file(argv[4]);
  OutFile outFile(argv[5]);
  std::vector<ProtectedBlockQueue> queueVector;
  std::vector<FileCompressor*> threads;
  for (int i = 0; i < (*argv[2] - '0'); i++) {
    queueVector.push_back(ProtectedBlockQueue(*argv[3] - '0'));
  }
  for (int i = 0; i < (*argv[2] - '0'); i++) {
    threads.push_back(new FileCompressor(&file, &queueVector[i], *argv[1] - '0', *argv[2] - '0', i));
    threads[i] -> start();
  }
  Writer writer(&queueVector, &outFile);
  writer.write();
  for (int i = 0; i < (*argv[2] - '0'); i++) {
    threads[i] -> join();
    delete threads[i];
  }
}
