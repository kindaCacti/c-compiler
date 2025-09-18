#ifndef STRING
#define STRING

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    void* ptr;
    uint64_t size;
    uint64_t maxSize;
} String;

void string_init(String *string){
    string->ptr = calloc(1, sizeof(char));
    string->size = 0;
    string->maxSize = 0;
}

void string_increase_size(String* string){
    uint64_t newSize = (string->maxSize + 1) << 1;
    void* newPointer = calloc(newSize, sizeof(char));
    memcpy(newPointer, string->ptr, string->size * sizeof(char));
    string->maxSize = newSize;

    free(string->ptr);

    string->ptr = newPointer;
}

void string_push_char(String *string, char c){
    if(string->maxSize < string->size + 1){
        string_increase_size(string);
    }
    *((char*)string->ptr + string->size) = c;
    string->size += 1;
}

#endif