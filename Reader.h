#ifndef _READER_H_
#define  _READER_H_
#include "File.h"
class Reader {
  private:
    File* inFIle;
  public:

    Reader(File* aFile);

    ~Reader();
};

#endif
