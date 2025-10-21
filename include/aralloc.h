#ifndef ARALLOC_H
#define ARALLOC_H

#include "types.h"

/*
    * THIS SHOULD BE THE ONLY WAY THAT ARENAS ARE CREATED.
    * Currently it uses malloc but it will late be migrated to Linux syscalls.
    * byte_count should be the number of bytes you intend to have in an Arena for its entire lifetime.
*/
Arena mkArena(size_t byte_count);


/*
 * Allocates more memory in an Arena's memory space.
 * The first argument should be measured in bytes, not objects.
 * If this call fails it will return NULL.
*/
void *newArenaObject(size_t chunk_size, Arena arena_used);


/*
 * Frees pStart and zeros out the struct.
 * DO NO USE ANY OTHER METHOD OF FREEING pStart!!
 * free() is called temporarily and syscalls will be implemented at a later date.
*/
void freeArena(Arena free_arena);

#endif // ARALLOC_H
