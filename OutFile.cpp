#include "OutFile.h"

OutFile::OutFile() {
  outFile = &std::cout;
  /*if (!outFile.is_open()) {
    cout << "chao" << endl;
  }*/
}

void OutFile::write(char *buf, int bytesToWrite) {
  outFile -> write(buf, bytesToWrite);
}

OutFile::~OutFile() {
}
