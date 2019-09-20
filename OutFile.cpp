#include "OutFile.h"
#include <fstream>
OutFile::OutFile(const char* filename) {
  if (*filename == '-') {
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
}
