#include "InFile.h"
#include "FileCompressor.h"
#include "OutFile.h"
#include "ProtectedBlockQueue.h"
#include "Writer.h"

int main(int argc, char const *argv[]) {
  InFile file(argv[4]);
  OutFile outFile(argv[5]);
  std::vector<ProtectedBlockQueue> queueVector;
  queueVector.push_back(ProtectedBlockQueue(*argv[3] - '0'));
  queueVector.push_back(ProtectedBlockQueue(*argv[3] - '0'));
  FileCompressor fileCompressor1(&file, &queueVector[0], *argv[1] - '0', 2, 0);
  FileCompressor fileCompressor2(&file, &queueVector[1], *argv[1] - '0', 2, 1);
  fileCompressor1.start();
  fileCompressor2.start();
  Writer writer(&queueVector, &outFile);
  writer.write();
  fileCompressor1.join();
  fileCompressor2.join();
}
