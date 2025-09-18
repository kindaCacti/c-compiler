#ifndef M_ARENA
#define M_ARENA

#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#define DEFAULT_ARENA_ALIGNMENT 2 * sizeof(void*)

typedef struct{
    void* base;
    uint64_t size;
    uint64_t position;
} M_Arena;

void m_arena_init(M_Arena* arena, int size){
    arena->base = malloc(size);
    arena->size = size;
    arena->position = 0;
}

void* m_arena_alloc(M_Arena* arena, int size){
    void* return_address = arena->base + arena->position;
    arena->position += size;

    return return_address;
}

void m_arena_increase(M_Arena* arena){
    uint64_t newSize = arena->size << 1;
    void* newArenaBase = malloc(newSize);
    memcpy(newArenaBase, arena->base, arena->size);
    arena->size = newSize;
    free(arena->base);
    arena->base = newArenaBase;
}

void m_arena_free(M_Arena* arena){
    free(arena->base);
}

#endif