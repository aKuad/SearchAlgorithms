# Py-SQLite

## Description

Making SQLite database file from a data file.

### Useage

2 arguments are required.

```sh
python3 sqlite_make.py <Input data file> <Output database file>
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

This script using only standard modules.
No additional modules require.

```sh
# example
python3 sqlite_make.py input.txt output.db
```
