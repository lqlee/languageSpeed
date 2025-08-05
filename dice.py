
import sys
import time
import random
import numpy as np

def roll (to_roll) :
  total = 0
  split = str.split(to_roll, 'd')
  amount = int(split[0])
  dice = int(split[1])
  # for i in range (amount) :
    # total += random.randint(1, dice)
  return np.sum(np.random.randint(1,  dice, amount) )

if len(sys.argv) != 2 :
  print('you need to provide your dice and amount ')
  print("For example : 2d4 or 1d20")
  exit(0)
start = time.time()
to_roll = sys.argv[1]
res = roll(to_roll)
end = time.time()

print(f' Python : {int(1000 * (end - start ))} ms, res : {res}')
