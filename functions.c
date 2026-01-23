//definitions for all functions used in main
//functions declared in header

#include "header.h"

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
