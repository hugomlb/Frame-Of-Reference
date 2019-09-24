#ifndef _FILE_COMPRESSOR_H_
#define  _FILE_COMPRESSOR_H_
#include "ProtectedInFile.h"
#include "ProtectedBitBlockQueue.h"
#include "Block.h"
#include "Thread.h"
class FileCompressor : public Thread {
  private:
    ProtectedInFile* inFile;
    ProtectedBitBlockQueue* queue;
    Block block;
    int numbsPerBlock;
    int numbOfThreads;
    int myNumb;

  public:
    explicit FileCompressor(ProtectedInFile* in, ProtectedBitBlockQueue* queue,
        int numbsPerBlock, int numbOfThreads, int myNumb);

    void run();

    ~FileCompressor();
};

#endif
