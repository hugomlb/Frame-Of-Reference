#include "FileCompressor.h"
#define END_OF_FILE -1
#define OK 0

FileCompressor::FileCompressor(InFile* in, OutFile* out, int numbsPerBlock)
                                :block(numbsPerBlock) {
  inFile = in;
  outFile = out;
  this -> numbsPerBlock = numbsPerBlock;
}

void FileCompressor::compress() {
  int fileState = OK;
  while (fileState == OK) {
    fileState = inFile -> readNumbsTo(&block, numbsPerBlock);
    if (!(block.hasSpace())) {
      BitBlock bitBlock = block.compress();
      bitBlock.writeTo(outFile);
      block.reset();
    }
  }
}

FileCompressor::~FileCompressor() {
}
