# C-BinTree

## Description

Binary tree search program from a data file.

`bintree_normal.cpp` is single binary tree structure algorithm.

`bintree_hash.cpp` is multi binary tree structure with hash function algorithm.

### Useage

Over 2 arguments are required.

```sh
./bintree_normal <Input data file> <Search id 1> <Search id 2> ...
./bintree_hash <Input data file> <Search id 1> <Search id 2> ...
```

### Input file example

```txt
29 38ea68
79 d1bb5c
73 5940b7
...
```

This data file can make with `/Datamake/data_make.py`.

### Output example

```sh
# example for: ./bintree_normal data.txt 79 29 73
243
79 d1bb5c 6
29 38ea68 2
73 5940b7 3
```

First line means progress time for data reading and inserting.

After 2nd lines means, (from left) id, value, searching progress time.
If the value was not found from specified id, the value will print "Not-found".

Progress time unit is microseconds.

## How to run

### Build

This program using only standard libraries.
No additional libraries require.

`makefile` is including in this directory.
To build, you only execute this command:

```sh
make
```

If you want to build manually, execute this.

```sh
g++ -Wall -O2 NodeBinTree.cpp bintree_normal.cpp -o bintree_normal
g++ -Wall -O2 NodeBinTree.cpp bintree_hash.cpp -o bintree_hash
```

### Run

In default, the executable file name is `bintree_normal`, `bintree_hash`.

```sh
# example for binary tree searching
./bintree_normal input.txt 26 81 13

# example for hash - binary tree searching
./bintree_hash input.txt 26 81 13
```
