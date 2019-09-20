#ifndef _FILE_COMPRESOR_H_
#define  _FILE_COMPRESOR_H_
#include "InFile.h"
#include "OutFile.h"
#include "Block.h"
class FileCompressor {
  private:
    InFile* inFile;
    OutFile* outFile;
    Block block;
    int numbsPerBlock;

  public:
    FileCompressor(InFile* in, OutFile* out, int numbsPerBlock);

    void compress();

    ~FileCompressor();
};

#endif
