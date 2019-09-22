
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
  FileCompressor fileCompressor(&file, &queueVector[0], *argv[1] - '0', 1, 0); //AL PRIMER HILO MANDAR 0 DE ULTIMO ARG
  fileCompressor.start();
  Writer writer(&queueVector, &outFile);
  writer.write();
  fileCompressor.join();
}
