#ifndef _OUT_FILE_H_
#define _OUT_FILE_H_

#include <ostream>
#include <iostream>
class OutFile {
  private:

    std::ostream* outFile;

  public:

    OutFile();

    void write(char* buf, int bytesToWrite);

    ~OutFile();
};


#endif