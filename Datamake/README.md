# Datamake

## Description

Random data makeing script.

### Useage

2 arguments are required.

```sh
python3 data_make.py <Number of data> <Output file name>
```

### Output example

```sh
# example for: ./bintree_normal data.txt 79 29 73
29 38ea68
79 d1bb5c
73 5940b7
...
```

These values means, (from left) id, value.

Id will takes unique number from 0 to data count - 1.

Value takes random hexadecimal from 0x100000 to 0xffffff.

## How to run

This script using only standard modules.
No additional modules require.

```sh
# example
python3 data_make.py 100 data.txt
```
