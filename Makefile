
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
	go run  dice.go 99999999d99999999
	python3 dice.py 99999999d99999999

clean:
	rm -f DotProduct.class dotproductc dotproductcpp

