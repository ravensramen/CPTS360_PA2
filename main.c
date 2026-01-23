//NAME: Sydnee Boothby
//Class: CPTS 360
//Assignment: PA2 Cache simulator

//This text file contains the main program, all user defined functions in header.h and functions.c
#include "header.h"

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
