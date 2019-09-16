#ifndef _FILE_COMPRESOR_H_
#define  _FILE_COMPRESOR_H_
#include "InFile.h"
#include "Block.h"
class FileCompressor {

  private:

    InFile* inFile;
    Block* block;

  public:

    FileCompressor(InFile* aFile, int numbsPerBlock);

    void compress();

    ~FileCompressor();
};

#endif
