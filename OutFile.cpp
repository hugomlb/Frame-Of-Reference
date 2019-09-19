#include "OutFile.h"
using namespace std;

OutFile::OutFile() {
  outFile = &cout;
  /*if (!outFile.is_open()) {
    cout << "chao" << endl;
  }*/
}

void OutFile::write(char *buf, int bytesToWrite) {
  outFile -> write(buf, bytesToWrite);
}

OutFile::~OutFile() {
}