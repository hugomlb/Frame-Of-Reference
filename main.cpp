#include "File.h"
#include "FileCompressor.h"
int main(int argc, char const *argv[]) {
  File file;
  FileCompressor fileCompressor(&file, 4);
  fileCompressor.compress();
  fileCompressor.compress();
  fileCompressor.compress();
  fileCompressor.compress();
  fileCompressor.compress();
}
