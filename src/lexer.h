#ifndef LEXER
#define LEXER

#include <stdio.h>

#include "tokens.h"
#include "./data_types/string.h"
#include "./data_types/trie.h"

void generate_tree(String* data){
    String buffer;
    string_init(&buffer);

    M_Arena memory_arena;
    m_arena_init(&memory_arena, 1 << 16);

    Trie token_trie;
    trie_init(&token_trie, &memory_arena);
    load_tokens_to_trie(&token_trie, &memory_arena);

    int it = 0;
    while(it < data->size){
        char currentChar = ((char*)data->ptr)[it];

        if(currentChar == ' '){
            if(buffer.size == 0) continue;
            int token_id = trie_find_word(&token_trie, buffer.ptr);
            printf("%s -> %d\n", (char*)buffer.ptr, token_id);
            string_clear(&buffer);
        } else {
            string_push_char(&buffer, currentChar);
        }

        it += 1;
    }

    printf("%s \n", (char*)buffer.ptr);
}

#endif