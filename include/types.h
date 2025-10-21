#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>
#include <inttypes.h>

/*
 * This struct contains a statically sized arena that contains data (of possibly heterogeneous types) that is intended to be freed together.
 * DO NOT EDIT ANY OF THE MEMBERS OF THE STRUCT DIRECTLY!!
*/
typedef struct arena{
    size_t _size;
    size_t _write;
    void *_pStart;
} Arena;


#endif // TYPES_H
