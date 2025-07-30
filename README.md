# languageSpeed

This project was inspired by a youtube video talking about Go Lang and Python speed.
https://www.youtube.com/watch?v=Q0hWo6LmUOw&list=WL&index=2

It said, Python numpy is faster than go. 
The code shows something different, the numpy runs even slower.

## Usage
```
make
make all // build

make run  // run all of them

make clean  // delete files 
```


## Output
With the random value assignment, the Go lang runs even faster than C/Java, becomes No 1.
```
$ make run
./dotproductc
 C  LEN : 10000000, init : 431 ms, dot product : 17 ms, total : 448 ms
./dotproductcpp
 C++  LEN : 10000000, init : 1714 ms, dot product : 20 ms.  total : 1734 ms
java DotProduct
 JAVA  LEN : 10000000, init : 382, dot product : 8 ms, total : 390 ms
go run dotproduct.go
 Golang LEN : 10000000, init : 231 ms, dot product : 75 ms, total : 306 ms
python3 dotproduct.py
 numpy version :  1.26.4
 Python LEN : 10000000  init : 1084 ms, dot product : 225 ms, total : 1309 ms, numpy dot product : 591 ms
```

Since the random generation also takes some time, and different languages have different implementation. so replacee it with a constant value '0.01'. The result shows something different, C++ becomes No 1 :

```
 $ make run
./dotproductc
 C  LEN : 10000000, init : 82 ms, dot product : 17 ms, total : 99 ms
./dotproductcpp
 C++  LEN : 10000000, init : 50 ms, dot product : 20 ms.  total : 70 ms
java DotProduct
 JAVA  LEN : 10000000, init : 64, dot product : 10 ms, total : 74 ms
go run dotproduct.go
 Golang LEN : 10000000, init : 131 ms, dot product : 88 ms, total : 219 ms
python3 dotproduct.py
 numpy version :  1.26.4
 Python LEN : 10000000  init : 401 ms, dot product : 228 ms, total : 630 ms, numpy dot product : 574 ms
```

If we care about the dot product calculation only, the Java seems No 1 (10<17<20).
