#include <stdio.h>
#include <stdlib.h>

#include "./data_types/m_arena.h"
#include "./data_types/string.h"
#include "compiler.h"

int32_t main(int32_t argc, char* argv[]){
    if(argc < 2){
        perror("no file given to compile\n");
        exit(1);
    }

    char* inputFilePath = argv[1];
    char* outputFilePath = "a.asm";

    if(argc >= 3) outputFilePath = argv[2];

    compile(inputFilePath, outputFilePath);

    return 0;
}