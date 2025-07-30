
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
	python3 dotproduct.py
	go run dotproduct.go

clean:
	rm -f DotProduct.class dotproductc dotproductcpp

