#include "OutFile.h"
#include <fstream>
OutFile::OutFile(const char* filename) {
  if (*filename == '-') {
    outFile = &std::cout;
  } else {
    FILE* fd = freopen(filename, "w", stdout);
    if (fd != NULL) {
      outFile = &std::cout;
    }
  }
}

void OutFile::write(char *buf, int bytesToWrite) {
  outFile -> write(buf, bytesToWrite);
}

OutFile::~OutFile() {
}
