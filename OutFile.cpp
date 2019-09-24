#include "OutFile.h"
#include <fstream>
#define COUT '-'

OutFile::OutFile(const char* filename) {
  if (*filename == COUT) {
    outFile = &std::cout;
  } else {
    fd = std::ofstream(filename, std::ios::binary);
    outFile = &fd;
    }
}

void OutFile::write(char *buf, int bytesToWrite) {
  outFile -> write(buf, bytesToWrite);
}

OutFile::~OutFile() {
  if (fd.is_open()) {
    fd.close();
  }
}
