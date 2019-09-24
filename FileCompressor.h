#ifndef _FILE_COMPRESSOR_H_
#define  _FILE_COMPRESSOR_H_
#include "InFile.h"
#include "ProtectedBitBlockQueue.h"
#include "Block.h"
#include "Thread.h"
class FileCompressor : public Thread {
  private:
    InFile* inFile;
    ProtectedBlockQueue* queue;
    Block block;
    int numbsPerBlock;
    int numbOfThreads;
    int myNumb;

  public:
    explicit FileCompressor(InFile* in, ProtectedBlockQueue* queue,
        int numbsPerBlock, int numbOfThreads, int myNumb);

    void run();

    ~FileCompressor();
};

#endif
