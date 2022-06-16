# coding: UTF-8
#
# sqlite_search.py
#
# Author: aKuad
#
# Published with CC0 license
#

# Modules importing
from sqlite3 import connect
from time import perf_counter
from sys import argv, stderr, exit


# Argument checking
if len(argv) < 3:
  print("Invalid arguments.", file=stderr)
  print("  Useage:", file=stderr)
  print("    %s <Input database file> <Search id 1> <Search id 2> ..." % argv[0], file=stderr)
  exit(1)


# Parameters settings
NAME_DB = argv[1]
NAME_TB = "data"


# Data searching
## Database connect
conn = connect(NAME_DB)
curs = conn.cursor()

## Data searching loop
for id in argv:
  # Ignore first argument
  if (id == argv[0]) or (id == argv[1]):
    continue
  # Timer start
  t_st = perf_counter()
  # Data searching
  curs.execute("select value from %s where id = %s;" % (NAME_TB, id))
  value = curs.fetchone()
  if value != None:
    print("%s %s" % (id, value[0]), end="")
  else:
    print("%s Not-found" % (id), end="")
  # Timer stop
  t_ed = perf_counter()
  # Data searching time printing
  print(" %d" % ((t_ed - t_st) * 1000))

## Database disconnect
conn.close()
