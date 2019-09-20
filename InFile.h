#ifndef _IN_FILE_H_
#define  _IN_FILE_H_
#include <istream>
#include "Block.h"
#include <fstream>
class InFile {
  private:
    std::istream* file;
    std::ifstream fd;
    unsigned lastRead;
    bool wasRead;
    int lectureNum;


    int isEOF();

  public:
    explicit InFile(const char* filename);

    int readNumbsTo(Block* block, int amountOfNumb);

    int readNumberTo(Block* block);

    ~InFile();
};

#endif
