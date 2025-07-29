
all : DotProduct.class dotproductc dotproductcpp

DotProduct.class :
  javac DotProduct.java

dotproductc :
  gcc dotproduct.c -o dotproductc

dotproductcpp :
  g++ dotproduct.cpp -o dotproductcpp

run :
  ./dotproductc
  ./dotproductcpp
  java DotProduct
  python3 dotproduct.py
  go run dotproduct.go

clean :
  rm -f DotProduct.class
  rm -f dotproductc
  rm -f dotproductcpp

