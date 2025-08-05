# Computer Language Speed Comparison

This project was inspired by a [youtube video](https://www.youtube.com/watch?v=Q0hWo6LmUOw&list=WL&index=2) talking about Go Lang and Python speed. and [this one](https://www.youtube.com/watch?v=pb6cmfYlogg)

So just curious, implemented the same idea with different languages, C / C ++ / JAVA / Go / Python / Numpy to see how it goes. 
It said, Python numpy is faster than Go. 
~~The code shows something different, the numpy runs even slower.~~  PYthon numpy is realy the fastest.

## Usage
```
make
make all // build

make run  // run all of them

make clean  // delete files 
```


## Output
With the random value initialization, the Go lang runs even faster than C/Java, becomes No 1 (306 < 390 < 448).
```
$ make run
./dotproductc
 C  LEN : 10000000, init : 431 ms, dot product : 17 ms, total : 448 ms
./dotproductcpp
 C++  LEN : 10000000, init : 1714 ms, dot product : 20 ms.  total : 1734 ms
java DotProduct
 JAVA  LEN : 10000000, init : 382 ms, dot product : 8 ms, total : 390 ms
go run dotproduct.go
 Golang LEN : 10000000, init : 231 ms, dot product : 75 ms, total : 306 ms
python3 dotproduct.py
 numpy version :  1.26.4
 Python LEN : 10000000 init : 1084 ms, dot product : 225 ms, total : 1309 ms, numpy dot product : 591 ms
```

Since the random value generation also takes some time, and the different languages have different implementations. so replace it with a constant value '0.01'. The result shows something different, C++ becomes No 1 (70 < 74 < 99):

```
 $ make run
./dotproductc
 C  LEN : 10000000, init : 82 ms, dot product : 17 ms, total : 99 ms
./dotproductcpp
 C++  LEN : 10000000, init : 50 ms, dot product : 20 ms.  total : 70 ms
java DotProduct
 JAVA  LEN : 10000000, init : 64 ms, dot product : 10 ms, total : 74 ms
go run dotproduct.go
 Golang LEN : 10000000, init : 131 ms, dot product : 88 ms, total : 219 ms
python3 dotproduct.py
 numpy version :  1.26.4
 Python LEN : 10000000  init : 401 ms, dot product : 228 ms, total : 630 ms, numpy dot product : 574 ms
```

If we care about the dot product calculation only, the Java seems No 1 (10 < 17 < 20).


## Updates
After review the video again, I found the issue why the numpy version is not faster, because I did not convert the arrays with numpy.
After conversion, the numpy version becomes No 1 (dot product only), even faster than Java (6 < 9).

```
 $ make run
./dotproductc
 C  LEN : 10000000, init : 79 ms, dot product : 18 ms, total : 97 ms
./dotproductcpp
 C++  LEN : 10000000, init : 51 ms, dot product : 19 ms.  total : 70 ms
java DotProduct
 JAVA  LEN : 10000000, init : 63 ms, dot product : 9 ms, total : 72 ms
go run dotproduct.go
 Golang LEN : 10000000, init : 183 ms, dot product : 115 ms, total : 298 ms
python3 dotproduct.py
 Python LEN : 10000000  init : 391 ms, dot product : 228 ms, total : 619 ms,
 numpy version :  1.26.4
 numpy array conversion : 445 ms, numpy dot product : 6 ms, total : 452 ms
```

After reviewed the numpy doc, found that numpy has its own array init, faster than Go.

```
$ make run
./dotproductc
 C  LEN : 10000000, init : 300 ms, dot product : 18 ms, total : 318 ms
./dotproductcpp
 C++  LEN : 10000000, init : 1597 ms, dot product : 18 ms.  total : 1615 ms
java DotProduct
 JAVA  LEN : 10000000, init : 375 ms, dot product : 10 ms, total : 385 ms
go run dotproduct.go
 Golang LEN : 10000000, init : 274 ms, dot product : 114 ms, total : 388 ms
python3 dotproduct.py
 Python LEN : 10000000  init : 439 ms, dot product : 254 ms, total : 693 ms,
 numpy version :  1.26.4
 numpy array init : 107 ms, numpy dot product : 6 ms, total : 114 ms
```


## Further Discussions
From this example, we can see how good the Go random value generation is, and how bad the C++ one is.</br> (231 - 131 :: 1714 - 50)

## Dice
when we convert the randint() loop to the randint() array generation and sum it. Python numpy takes almost half time as Go Lang.
```
go run  dice.go 99999999d99999999
 Go Lang : 1419 ms, res : 5000131220556710
 python3 dice.py 99999999d99999999
 Python : 763 ms, res : 4999762141799202
```

