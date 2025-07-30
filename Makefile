
all: DotProduct.class dotproductc dotproductcpp

DotProduct.class : DotProduct.java
	javac DotProduct.java

dotproductc : dotproduct.c 
	gcc dotproduct.c -o dotproductc

dotproductcpp : dotproduct.cpp
	g++ dotproduct.cpp -o dotproductcpp

run:
	./dotproductc
	./dotproductcpp
	java DotProduct
	go run dotproduct.go
	python3 dotproduct.py

clean:
	rm -f DotProduct.class dotproductc dotproductcpp

