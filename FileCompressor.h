#ifndef _FILE_COMPRESOR_H_
#define  _FILE_COMPRESOR_H_
#include "File.h"
#include "Block.h"
class FileCompressor {

  private:

    File* inFile;
    Block* block;


    void findMinAndMax();

    void sustractReference();

    int getNumOfBitsOfBlock();

  public:

    FileCompressor(File* aFile, int numbsPerBlock);

    void compress();

    ~FileCompressor();
};

#endif
