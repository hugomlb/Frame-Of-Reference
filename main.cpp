#include "InFile.h"
#include "FileCompressor.h"

#include <iostream>
#include "BitVector.h"

int main(int argc, char const *argv[]) {
  InFile file;
  FileCompressor fileCompressor(&file, 4);
  fileCompressor.compress();
/*  char a;
  unsigned x = 0;
  for (int i = 0; i < 8; ++i) {
    if (i == 0 || i == 6) {
      x = 1;
    } else {
      x = 0;
    }
    a = (a &~ (1UL << i)) | (x << i);
  }
  std::cout << a << std::endl;*/
}
