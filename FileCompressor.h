#ifndef _FILE_COMPRESOR_H_
#define  _FILE_COMPRESOR_H_
#include "InFile.h"
#include "ProtectedBlockQueue.h"
#include "Block.h"
#include "Thread.h"
class FileCompressor : public Thread {
  private:
    InFile* inFile;
    ProtectedBlockQueue* queue;
    Block block;
    int numbsPerBlock;

  public:
    explicit FileCompressor(InFile* in, ProtectedBlockQueue* queue,
        int numbsPerBlock);

    void run();

    ~FileCompressor();
};

#endif
