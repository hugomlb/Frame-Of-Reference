#ifndef _IN_FILE_H_
#define  _IN_FILE_H_
#include <istream>
#include "Block.h"
#include <mutex>
#include <fstream>
class ProtectedInFile {
  private:
    std::istream* file;
    std::ifstream fd;
    std::mutex mutex;
    unsigned lastRead;
    bool wasRead;
    int size;

    int readNumberTo(Block* block);

    int isEOF();

  public:
    explicit ProtectedInFile(const char* filename);

    int readNumbsToStartingAt(Block *block, int position);

    ~ProtectedInFile();
};

#endif
