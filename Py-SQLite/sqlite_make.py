# coding: UTF-8
#
# sqlite_make.py
#
# Author: aKuad
#
# Published with CC0 license
#

# Modules importing
from sqlite3 import connect
from subprocess import call
from time import perf_counter


# Parameters settings
NAME_DB = "data.db"
NAME_TB = "data"
NAME_TX = "../data.txt"


# Database making
## Database connect
call("echo -n > %s" % NAME_DB, shell=True)  # Exist file removing
conn = connect(NAME_DB)
curs = conn.cursor()

## Timer start
t_st = perf_counter()

## Table make
curs.execute("create table %s (id int, value char(6));" % NAME_TB)

## Data inserting
with open(NAME_TX, "r") as f:
  for line in f.readlines():
    data = line.strip().split(" ")
    curs.execute("insert into %s values (%s, '%s');" % (NAME_TB, data[0], data[1]))

## Timer stop
t_ed = perf_counter()

## Database disconnect
conn.commit()
conn.close()


# Process time printing
print("%f" % ((t_ed - t_st) * 1000))
