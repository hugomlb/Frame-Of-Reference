#ifndef _FILE_COMPRESOR_H_
#define  _FILE_COMPRESOR_H_
#include "InFile.h"
#include "ProtectedBlockQueue.h"
#include "Block.h"

#include "OutFile.h"
class FileCompressor {
  private:
    InFile* inFile;
    ProtectedBlockQueue* queue;
    Block block;
    int numbsPerBlock;

  public:
    explicit FileCompressor(InFile* in, ProtectedBlockQueue* queue,
        int numbsPerBlock);

    void compress();

    ~FileCompressor();
};

#endif
