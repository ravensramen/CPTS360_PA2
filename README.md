# CPTS360_PA2

Sydnee Boothby 01/29

Compilation and Running Instructions:
run with " ./myproject 64 16 input_sequence.txt" command, configure cache simulation as desired (try different txts and cache/block sizes)
add -lm when compiling flag to include math.h log functions

Assumptions Made:
Cache is direct-mapped, each line coresponds to one location in main memory (simple but miss prone)

Example Input: (from input_sequence.txt)
0
4
8
12
16
20
24
28
32
36

Expected Output:

Total memory accesses: 10
Cache hits: 7
Cache misses: 3
Cache hit rate: 70.00%
