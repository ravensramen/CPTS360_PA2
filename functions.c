//definitions for all functions used in main
//functions declared in header

#include "header.h"

/*
 * Creates and initializes a cache struct, made up of multiple cache lines
 */
Cache* create_cache(int cache_size, int block_size) {
    Cache* cache = (Cache*)malloc(sizeof(Cache));
    if (cache == NULL) {
        return NULL;
    }

    cache->block_size = block_size; //block size according to input args
    cache->num_lines = cache_size / block_size; //lines dependent on cache and block sizes

    //allocate memory for array of lines
    cache->lines = (CacheLine*)malloc(sizeof(CacheLine) * cache->num_lines);

    //check for proper allocation
    if (cache->lines == NULL) {
        free(cache); //free memory if failed
        return NULL;
    }

    //Initialize cache lines as empty
    for(int i = 0; i< cache->num_lines; i++){
        cache->lines[i].valid = 0;
        cache->lines[i].tag = 0;
    }
    return cache;
}

/*
 * Simulates accessing the cache with a memory address
 * Returns 1 for hit, 0 for miss
 */
int access_cache(Cache* cache, unsigned int address) {

    int wordBits = 0, indexBits=0; 

    //get word and index bits according to cache size 
    wordBits = log2(cache->block_size); 
    indexBits = log2(cache->num_lines); 


    int index = (address >> wordBits) & ((1<<indexBits) -1); //remove block offset -> get just tag and index values
    int tag = address >> (wordBits + indexBits); //extract tag (find where in memory to check for address)

    //check for a hit 
    if (cache->lines[index].valid && cache->lines[index].tag == tag){ //if valid (line has been used before) and tag matches block
        return 1; //hit
    }

    //If not a match, update the cache with the new load
    cache->lines[index].valid = 1;
    cache->lines[index].tag = tag; //simulate loading a new block
    return 0; //denote miss
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
