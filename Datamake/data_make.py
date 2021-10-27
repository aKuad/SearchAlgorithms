# coding: UTF-8
#
# data_make.py
#
# Author: aKuad
#
# Published with CC0 license
#

# Modules importing
from random import randint
from sys import argv, stderr, exit


# Arguments checking
if len(argv) != 3:
  print("Invalid arguments.", file=stderr)
  print("  Useage:", file=stderr)
  print("    %s <Number of data> <Output file name>" % argv[0], file=stderr)
  exit(1)


# Parameters settings
DATA_COUNT = int(argv[1])
DATA_NAME = argv[2]

# Data making and writing
with open(DATA_NAME, 'w') as f:
  nums = list(range(DATA_COUNT))

  for i in range(DATA_COUNT):
    f.write("%d %x\n" % (nums.pop(randint(0, len(nums) - 1)), randint(0x100000, 0xffffff)))
