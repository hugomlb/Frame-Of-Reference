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
    int size;

    int readNumberTo(Block* block);

    int isEOF();

  public:
    explicit InFile(const char* filename);

    int readNumbsToStartingAt(int amountOfNumb, Block* block, int position);

    void readStartingIn(int position);

    ~InFile();
};

#endif
