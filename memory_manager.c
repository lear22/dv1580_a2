#include "memory_manager.h"

static unsigned char* memory_pool = NULL;  // Pointer to the memory pool
static size_t pool_size = 0;  // Size of the memory pool
static Block* free_list = NULL;  // Head of the free list

void mem_init(size_t size) 
{
    if (size == 0) 
    {
        fprintf(stderr, "Memory pool size must be greater than 0.\n");
        return;
    }

    memory_pool = (unsigned char*)malloc(size + sizeof(Block));
    if (!memory_pool) 
    {
        fprintf(stderr, "Memory allocation for pool failed.\n");
        return;
    }

    pool_size = size;
    free_list = (Block*)memory_pool;  // Initialize the free list
    free_list->size = size;  // Set size of the first block
    free_list->next = NULL;  // No next block yet
    free_list->free = 1;  // Mark as free
}

void* mem_alloc(size_t size) 
{
    if (size == 0) 
    {
        return NULL;
    }

    Block* current = free_list;
    while (current) 
    {
        if (current->free && current->size >= size) 
        {
            // Allocate memory from this block
            current->free = 0; // Mark as allocated
            if (current->size > size + sizeof(Block)) 
            {
                // Split the block if too large
                Block* new_block = (Block*)((unsigned char*)current + sizeof(Block) + size);
                new_block->size = current->size - size - sizeof(Block);
                new_block->next = current->next;
                new_block->free = 1;
                current->size = size;  // Resize the current block
                current->next = new_block;  // Link the new block
            }
            return (void*)((unsigned char*)current + sizeof(Block));  // Return pointer to usable memory
        }
        current = current->next;
    }

    // No suitable block found
    return NULL;
}

void mem_free(void* block) 
{
    if (block == NULL) 
    {
        return;
    }

    // Find the block in the free list
    Block* to_free = (Block*)((unsigned char*)block - sizeof(Block));
    to_free->free = 1;  // Mark block as free
}

void* mem_resize(void* block, size_t size) 
{
    if (block == NULL) 
    {
        return mem_alloc(size);  // Equivalent to allocation
    }

    if (size == 0) 
    {
        mem_free(block);
        return NULL;
    }

    Block* old_block = (Block*)((unsigned char*)block - sizeof(Block));
    if (old_block->size >= size) 
    {
        return block;  // No need to resize
    }

    // Allocate a new block and copy the old data
    void* new_block = mem_alloc(size);
    if (new_block) 
    {
        memcpy(new_block, block, old_block->size);  // Copy data
        mem_free(block);  // Free old block
    }

    return new_block;  // Return new block
}

void mem_deinit() 
{
    free(memory_pool);
    memory_pool = NULL;
    pool_size = 0;
    free_list = NULL;  // Clean up free list
}
