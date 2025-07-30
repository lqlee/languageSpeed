# languageSpeed

This project was inspired by a youtube video talking about Go Lang and Python speed.
https://www.youtube.com/watch?v=Q0hWo6LmUOw&list=WL&index=2

It said, Python numpy is faster than go. 
The code shows something different, the numpy runs even slower.

## Usage
`make`
`make all // build` 

`make run  // run all of them`

`make clean  // delete files `


## Output
`
$ make run

./dotproductc

 C  LEN : 10000000, init : 431 ms, dot product : 17 ms, total : 448 ms
./dotproductcpp
 C++  LEN : 10000000, init : 1714 ms, dot product : 20 ms.  total : 1734 ms
java DotProduct
 JAVA  LEN : 10000000, init : 382, dot product : 8 ms, total : 390 ms
python3 dotproduct.py
 numpy version :  1.26.4
 Python LEN : 10000000  init two arrays : 1084 ms, dot product time : 225 ms, total : 1309 ms,  numpy dot product time : 591 ms,
go run dotproduct.go
 Golang LEN : 10000000, init : 231 ms, dot product : 75 ms, total : 231 ms
`
