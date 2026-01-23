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

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <cache_size> <block_size> <input_file>\n", argv[0]);
        return 1;
    }

    int cache_size = atoi(argv[1]);   // in bits
    int block_size = atoi(argv[2]);   // in bits
    char* filename = argv[3];

    Cache* cache = create_cache(cache_size, block_size);
    if (cache == NULL) {
        printf("Error creating cache\n");
        return 1;
    }

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        free_cache(cache);
        return 1;
    }

    unsigned int address;
    int accesses = 0;
    int hits = 0;
    int misses = 0;

    /* Read memory addresses from file */
    while (fscanf(fp, "%x", &address) == 1) {
        accesses++;
        if (access_cache(cache, address)) {
            hits++;
        }
        else {
            misses++;
        }
    }

    fclose(fp);
    print_stats(accesses, hits, misses);
    free_cache(cache);

    return 0;
}

/*
 * Creates and initializes a cache
 */
Cache* create_cache(int cache_size, int block_size) {
    Cache* cache = (Cache*)malloc(sizeof(Cache));
    if (cache == NULL) {
        return NULL;
    }

    cache->block_size = block_size;
    cache->num_lines = cache_size / block_size;

    cache->lines = (CacheLine*)malloc(sizeof(CacheLine) * cache->num_lines);
    if (cache->lines == NULL) {
        free(cache);
        return NULL;
    }

    /* TODO: Initialize cache lines (valid bits and tags) */

    return cache;
}

/*
 * Simulates accessing the cache with a memory address
 * Returns 1 for hit, 0 for miss
 */
int access_cache(Cache* cache, unsigned int address) {
    /* TODO:
     * 1. Compute block address
     * 2. Compute index
     * 3. Compute tag
     * 4. Check for hit or miss
     * 5. Update cache line on miss
     */

    return 0;  // placeholder
}

/*
 * Frees allocated memory for the cache
 */
void free_cache(Cache* cache) {
    if (cache != NULL) {
        free(cache->lines);
        free(cache);
    }
}

/*
 * Prints cache statistics
 */
void print_stats(int accesses, int hits, int misses) {
    double hit_rate = 0.0;
    if (accesses > 0) {
        hit_rate = (double)hits / accesses * 100.0;
    }

    printf("Total memory accesses: %d\n", accesses);
    printf("Cache hits: %d\n", hits);
    printf("Cache misses: %d\n", misses);
    printf("Cache hit rate: %.2f%%\n", hit_rate);
}
