#ifndef _FILE_H_
#define  _FILE_H_
#include <fstream>
class File {
  
  private:
    std::ifstream file;

  public:

    File();

    ~File();
};

#endif
