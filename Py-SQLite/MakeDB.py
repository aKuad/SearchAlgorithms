# coding: UTF-8
#
# MakeDB.py
#
# Author: aKuad
#
# Published with CC0 license
#

# Modules importing
from sqlite3 import connect
from subprocess import call


# Parameters settings
NAME_DB = "data.db"
NAME_TB = "data"
NAME_TEXT = "../data.txt"


# Database making
## Database connect
conn = connect(NAME_DB)
curs = conn.cursor()

## Table make
call("echo -n > %s" % NAME_DB, shell=True)
curs.execute("create table %s (id int, value char(6));" % NAME_TB)

## Data inserting
with open(NAME_TEXT, "r") as f:
  for line in f.readlines():
    data = line.strip().split(" ")
    curs.execute("insert into %s values (%s, '%s');" % (NAME_TB, data[0], data[1]))

## Database disconnect
conn.commit()
conn.close()
