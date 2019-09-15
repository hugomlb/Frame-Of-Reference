#ifndef _FILE_COMPRESOR_H_
#define  _FILE_COMPRESOR_H_
#include "File.h"
class FileCompressor {

  private:

    File* inFIle;
    int numbsPerBlock;


    void findMinAndMax();

    void sustractReference();

    int getNumOfBitsOfBlock();

  public:

    FileCompressor(File* aFile, int numbsPerBlock);

    void compress();

    ~FileCompressor();
};

#endif
