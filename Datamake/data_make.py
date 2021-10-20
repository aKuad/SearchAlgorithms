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

# Parameters settings
DATA_COUNT = 1000
DATA_NAME = "../data.txt"

# Data making and writing
with open(DATA_NAME, 'w') as f:
  nums = list(range(DATA_COUNT))

  for i in range(DATA_COUNT):
    f.write("%d %x\n" % (nums.pop(randint(0, len(nums) - 1)), randint(0x000000, 0xffffff)))
