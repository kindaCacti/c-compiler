#ifndef FILE_READER
#define FILE_READER

#include <stdio.h>
#include <stdlib.h>
#include "./data_types/string.h"

FILE* open_read_file(char* path){
    FILE* readFile = fopen(path, "r");
    
    if(readFile == NULL){
        perror("no such file exists");
        exit(1);
    }
    return readFile;
}

int64_t get_file_size(FILE* file){
    fseek(file, 0L, SEEK_END);
    int64_t fileSize = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return fileSize;
}

void read_file(FILE* fileToRead, String* buffer){
    char currentChar;
    while((currentChar = fgetc(fileToRead)) != EOF){
        string_push_char(buffer, currentChar);
    }
}

#endif