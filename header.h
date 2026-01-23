//preprocessor directives and function/class definitions here

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * Cache line structure
 * valid: indicates whether the line contains valid data
 * tag: stores the tag portion of the address
 */
typedef struct {
    int valid;
    unsigned int tag;
} CacheLine;

/*
 * Cache structure
 * lines: array of cache lines
 * num_lines: number of cache lines in the cache
 * block_size: size of each block in bits
 */
typedef struct {
    CacheLine* lines;
    int num_lines;
    int block_size;
} Cache;

/* Function prototypes */
Cache* create_cache(int cache_size, int block_size);
void free_cache(Cache* cache);
int access_cache(Cache* cache, unsigned int address);
void print_stats(int accesses, int hits, int misses);