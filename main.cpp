#include "InFile.h"
#include "FileCompressor.h"
int main(int argc, char const *argv[]) {
  InFile file;
  FileCompressor fileCompressor(&file, 4);
  fileCompressor.compress();
}
