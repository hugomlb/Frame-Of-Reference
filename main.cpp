#include "InFile.h"
#include "FileCompressor.h"

int main(int argc, char const *argv[]) {
  InFile file;
  OutFile outFile;
  FileCompressor fileCompressor(&file, &outFile, *argv[1] - '0');
  fileCompressor.compress();
}
