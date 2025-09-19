#ifndef COMPILER
#define COMPILER

#include "./data_types/string.h"
#include "file_reader.h"
#include "lexer.h"

void compile(char* inputFilePath, char* outputFilePath){
    String inputFileData;
    string_init(&inputFileData);

    FILE* inputFilePtr = open_read_file(inputFilePath);
    read_file(inputFilePtr, &inputFileData);

    generate_tree(&inputFileData);
}

#endif