#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_POOL_SIZE 1024  // Adjust as needed

// Block structure to manage memory
typedef struct Block 
{
    size_t size;  // Size of the block
    struct Block* next;  // Pointer to the next block in the free list
    int free;  // 1 if free, 0 if allocated
} Block;

// Function prototypes
void mem_init(size_t size);
void* mem_alloc(size_t size);
void mem_free(void* block);
void* mem_resize(void* block, size_t size);
void mem_deinit();

#endif  // MEMORY_MANAGER_H
