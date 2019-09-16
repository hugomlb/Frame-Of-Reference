#ifndef _IN_FILE_H_
#define  _IN_FILE_H_
#include <fstream>
#include "Block.h"
class InFile {

  private:
    std::ifstream file;

    int isEOF();
  public:

    InFile();

    int readNumberTo(Block* block);

    ~InFile();
};

#endif
