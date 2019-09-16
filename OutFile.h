#ifndef _OUT_FILE_H_
#define _OUT_FILE_H_

#include <fstream>

class OutFile {
  private:

    std::ofstream outFile;

  public:

    OutFile(char* filename);

    void write(char* buf, int bytesToWrite);

    ~OutFile();
};


#endif