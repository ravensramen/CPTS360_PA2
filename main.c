//NAME: Sydnee Boothby
//Class: CPTS 360
//Assignment: PA2 Cache simulator

//Program takes in "addresses" in input_sequence.txt, each item represents
//one byte in memory. Addresses are accessed one at a time, simulating access of cache blocks
//Program outputs statistics of total accesses, cache hit/misses, and hit rate
//Hardware specifics/cache configuration hard coded in program. 

//This text file contains the main program, all user defined functions in header.h and functions.c
#include "header.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {  //insufficient command line args
        printf("Usage: %s <cache_size> <block_size> <input_file>\n", argv[0]);
        return 1;
    }

    //cache config args
    int cache_size = atoi(argv[1]);   // in bits
    int block_size = atoi(argv[2]);   // in bits
    char* filename = argv[3];

    Cache* cache = create_cache(cache_size, block_size);
    if (cache == NULL) {
        printf("Error creating cache\n");
        return 1;
    }

    FILE* fp = fopen(filename, "r"); //create file pointer to command arg
    if (fp == NULL) { //check valid file open
        printf("Error opening input file\n");
        free_cache(cache);
        return 1;
    }

    unsigned int address; //store hex conversion of address from txt
    //variables for stats
    int accesses = 0;
    int hits = 0;
    int misses = 0;

    /* Read memory addresses from file */
    while (fscanf(fp, "%x", &address) == 1) { //stores hex of address
        accesses++;
        if (access_cache(cache, address)) { //if cache contains address
            hits++;
        }
        else { //cache does not contain address
            misses++;
        }
    }

    fclose(fp);
    print_stats(accesses, hits, misses);
    free_cache(cache);

    return 0;
}
