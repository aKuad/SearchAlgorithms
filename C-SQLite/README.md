# C-SQLite

## Description

Making SQLite database file from a data file.

### Useage

2 arguments are required.

```sh
./sqlite_make <Input data file> <Output database file>
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

```txt
21946
```

This number means total progress time for database query.
Unit is microseconds.

## How to run

### Required library installation

`sqlite_make.cpp` is using `sqlite3.h`.
To use `sqlite3.h`, additional libraries must be installed.

On Ubuntu, you can install sqlite3 library with this command:

```sh
sudo apt install libsqlite3-dev
```

In other platforms, please check the package name or package is available.

### Build

`makefile` is including in this directory.
To build, you only execute this command:

```sh
make
```

If you want to build manually, execute this.

```sh
g++ -Wall -O2 sqlite_make.cpp -lsqlite3 -o sqlite_make
```

### Run

In default, the executable file name is `sqlite_make`.

```sh
# example
./sqlite_make input.txt output.db
```
