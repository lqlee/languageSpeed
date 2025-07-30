'''
 run by :
 $ python3 dotproduct.py
'''
import numpy as np
import random as rd
import time
import psutil
import os

def get_memory_usage():
  memory_info = psutil.virtual_memory()
  print(f"{memory_info.available / (1024**3):.2f} GB  ", f"{(100-memory_info.percent) :.2f}", '%  ', f"{memory_info.total / (1024**3):.2f} GB  ")


LEN = 10000000

def dotProduct (arr, brr) :
  #print(f' LEN : {LEN}  dot product')
  result = 0.0
  for i in range(LEN) :
    result += arr[i] * brr[i]
  return result

def get_process_memory():
  print(' os.getpid() : ', os.getpid())
  process = psutil.Process(os.getpid())
  mem_info = process.memory_info()
  return mem_info.rss

if __name__ == "__main__":
  #get_memory_usage()
  arr, brr = [], []
  print(' numpy version : ', np.__version__)

  #memRss = get_process_memory()
  #print(" memRss : {:,} ".format( memRss))

  #get_memory_usage()
  #print(f' LEN : {LEN}  init two arrays, ')
  start = time.time()
  for i in range(LEN) :
    arr.append(0.01) #rd.random())
    brr.append(0.01) #rd.random())
  mid = time.time()
  #get_memory_usage()
  #print(f' python two arrays init time {int(1000 * (end - start))} ms, start : {start} ms, end : {end} ms ')
  #print(f' python two arrays init time {int(1000 * (end - start))} ms,  ')

  #memRss = get_process_memory()
  #print(" memRss : {:,} ".format( memRss))
  #start = time.time()
  res = dotProduct(arr, brr)
  end = time.time()
  #get_memory_usage()
  #print(f' python time {int(1000 * (end - start))} ms, start : {start} ms, end : {end} ms. result : {res} ')
  #print(f' python time {int(1000 * (end - start))} ms,  ')

  npStart = time.time()
  res = np.dot(arr, brr)
  npEnd = time.time()
  #get_memory_usage()
  #print(f' numpy time {int(1000 * (end - start))} ms, start : {start} ms, end : {end} ms.  result : {res} ')
  print(f' Python LEN : {LEN}  init : {int(1000 * (mid - start))} ms, ' +
    f'dot product : {int(1000 * (end - mid))} ms, total : {int(1000 * (end - start))} ms,' +
    f' numpy dot product : {int(1000 * (npEnd - npStart))} ms,  ')
