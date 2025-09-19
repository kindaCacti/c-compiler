#ifndef TRIE
#define TRIE

#include "m_arena.h"
#include "string.h"

#define TRIE_CHILDREN_AMMOUNT 256

typedef struct Trie_Node{
    void** children;
    int value;
} Trie_Node;

typedef struct {
    Trie_Node root;
} Trie;

void trie_init(Trie* trie, M_Arena* arena){
    void* children_ptr = m_arena_alloc(arena, TRIE_CHILDREN_AMMOUNT * sizeof(Trie_Node*));
    trie->root.children = children_ptr;
}

Trie_Node* trie_node_create(M_Arena* arena){
    Trie_Node* node_ptr = (Trie_Node*)m_arena_alloc(arena, sizeof(Trie_Node));
    node_ptr->value = -1;
    node_ptr->children = m_arena_alloc(arena, TRIE_CHILDREN_AMMOUNT * sizeof(Trie_Node*));
    return node_ptr;
}

Trie_Node* trie_node_go_to_child(Trie_Node* node, char character, M_Arena* arena){
    int child_id = (int)character;
    if(node->children[(int)child_id] == NULL){
        Trie_Node* child_node = trie_node_create(arena);
        node->children[(int)child_id] = child_node;
    }

    return node->children[child_id]; 
}

void trie_add_word(Trie* trie, char* word, int value, M_Arena* arena){
    Trie_Node* current_node = &trie->root;
    int it = 0;

    while(word[it] != 0){
        char character = word[it];
        Trie_Node* child = trie_node_go_to_child(current_node, character, arena);;
        current_node = child;
        it++;
    }

    current_node->value = value;
}

void trie_add_word_s(Trie* trie, String* word, int value, M_Arena* arena){
    trie_add_word(trie, word->ptr, value, arena);
}

int trie_find_word(Trie* trie, char* word){
    Trie_Node* current_node = &trie->root;
    int it = 0;

    while(word[it] != 0){
        char character = word[it];
        if(current_node->children[(int)character] == NULL) return -1;
        current_node = current_node->children[(int)character];
        it++;
    }

    return current_node->value;
}

int trie_find_word_s(Trie* trie, String* word){
    return trie_find_word(trie, word->ptr);
}


#endif