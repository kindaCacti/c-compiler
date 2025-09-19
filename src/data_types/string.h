#ifndef STRING
#define STRING

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"

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

int string_compare(String* s1, String* s2){
    int len = min(s1->size, s2->size);

    for(int i = 0; i<len; i++){
        if(((char*)s1->ptr)[i] == ((char*)s2->ptr)[i]) continue;
        return (int)(((char*)s1->ptr)[i] > ((char*)s2->ptr)[i]) * 2 - 1;
    }

    if(s1->size == s2->size) return 0;
    return (int)(s2->size < s1->size) * 2 - 1;
}
 
void string_push_char(String *string, char c){
    if(string->maxSize < string->size + 1){
        string_increase_size(string);
    }
    *((char*)string->ptr + string->size) = c;
    string->size += 1;
}

void string_pop_char(String *string){
    if(string->size < 0) return;

    string->size -= 1;
    ((char*)string->ptr)[string->size] = 0;
}

#endif