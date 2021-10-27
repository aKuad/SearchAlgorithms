# C-Liner

## Description

Liner search program from a data file.

`liner_normal.cpp` is single liner structure algorithm.

`liner_hash.cpp` is multi liner structure with hash function algorithm.

### Useage

Over 2 arguments are required.

```sh
./liner_normal <Input data file> <Search target 1> <Search target 2> ...
./liner_hash <Input data file> <Search target 1> <Search target 2> ...
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
# example for: ./liner_normal data.txt 79 29 73
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
g++ -Wall -O2 NodeLiner.cpp liner_normal.cpp -o liner_normal
g++ -Wall -O2 NodeLiner.cpp liner_hash.cpp -o liner_hash
```

### Run

In default, the executable file name is `liner_normal`, `liner_hash`.

```sh
# example for liner searching
./liner_normal input.txt 26 81 13

# example for hash - liner searching
./liner_hash input.txt 26 81 13
```
