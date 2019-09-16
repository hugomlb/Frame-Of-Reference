#ifndef _OUT_FILE_H_
#define _OUT_FILE_H_

#include <fstream>
#include <iostream>
class OutFile {
  private:

    std::ofstream outFile;

  public:

    OutFile();

    void write(char* buf, int bytesToWrite);

    ~OutFile();
};


#endif