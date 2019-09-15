#ifndef _FILE_COMPRESOR_H_
#define  _FILE_COMPRESOR_H_
#include "File.h"
class FileCompressor {
  private:
    File* inFIle;
  public:

    FileCompressor(File* aFile);

    ~FileCompressor();
};

#endif
