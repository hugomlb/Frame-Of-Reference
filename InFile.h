#ifndef _IN_FILE_H_
#define  _IN_FILE_H_
#include <istream>
#include "Block.h"
class InFile {
  private:
    std::istream* file;
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
