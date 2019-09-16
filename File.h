#ifndef _FILE_H_
#define  _FILE_H_
#include <fstream>
#include "Block.h"
class File {

  private:
    std::ifstream file;

    int isEOF();
  public:

    File();

    int readNumberTo(Block* block);

    ~File();
};

#endif
