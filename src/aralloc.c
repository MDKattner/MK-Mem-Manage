#include "aralloc.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
    * THIS SHOULD BE THE ONLY WAY THAT ARENAS ARE CREATED.
    * Currently it uses malloc but it will late be migrated to Linux syscalls.
    * byte_count should be the number of bytes you intend to have in an Arena for its entire lifetime.
*/
Arena mkArena(size_t byte_count){
    struct arena arena_out;
    arena_out.pStart = malloc(byte_count);
    arena_out.size = byte_count;
    arena_out.write = (size_t)arena_out.pStart;
    return arena_out;
}

void *newArenaObject(size_t chunk_size, Arena arena_used){
    if(chunk_size > (size_t)arena_used.pStart + arena_used.size - arena_used.write){
        fprintf(stderr, "Not enough space on Arena for allocation: %lu bytes remaning", 
                (size_t)arena_used.pStart + arena_used.size - arena_used.write);
        return NULL;
    }
    void *pOut = (void*)((size_t)arena_used.pStart + arena_used.write);
    arena_used.write += chunk_size;

    return pOut;
}

void freeArena(Arena free_arena){
    free(free_arena.pStart);
    free_arena.pStart = NULL;
    free_arena.write = 0;
    free_arena.size = 0;
}
