#ifndef _IN_FILE_H_
#define  _IN_FILE_H_
#include <fstream>
#include "Block.h"
class InFile {

  private:
    std::ifstream file;
    unsigned lastRead;
    bool wasRead;
    int lectureNum;
    int isEOF();
  public:

    InFile();

    int readNumbsTo(Block* block, int amountOfNumb);

    int readNumberTo(Block* block);

    ~InFile();
};

#endif
