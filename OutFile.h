#ifndef _OUT_FILE_H_
#define _OUT_FILE_H_

#include <ostream>
#include <iostream>
#include <fstream>
class OutFile {
  private:
    std::ostream* outFile;
    std::ofstream fd;

  public:
    OutFile(const char* filename);

    void write(char* buf, int bytesToWrite);

    ~OutFile();
};


#endif
