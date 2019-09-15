#include "Reader.h"
#include "File.h"
int main(int argc, char const *argv[]) {
  File file;
  int x=0;
  while(x != -1) {
    x = file.readNumber();
    printf("%x\n", x);
  }
  return 0;
}
