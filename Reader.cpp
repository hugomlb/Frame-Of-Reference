#include "Reader.h"
#include <iostream>
#include <fstream>
using namespace std;

Reader::Reader(File* aFile) {
  this -> inFIle = aFile;
}

Reader::~Reader() {

}
