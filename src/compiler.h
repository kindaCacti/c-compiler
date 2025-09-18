#ifndef COMPILER
#define COMPILER

#include "string.h"
#include "file_reader.h"

void compile(char* inputFilePath, char* outputFilePath){
    String inputFileData;
    string_init(&inputFileData);

    FILE* inputFilePtr = open_read_file(inputFilePath);
    read_file(inputFilePtr, &inputFileData);

    printf("%s\n", (char*)inputFileData.ptr);
}

#endif