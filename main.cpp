#include "InFile.h"
#include "FileCompressor.h"

int main(int argc, char const *argv[]) {
  InFile file;
  OutFile outFile;
  FileCompressor fileCompressor(&file, &outFile, 3);
  fileCompressor.compress();
}
