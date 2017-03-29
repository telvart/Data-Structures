lab9: main.o BinomialQueue.o BNode.o
	g++ -g -Wall -std=c++11 -o lab9 main.o BinomialQueue.o BNode.o
main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
BinomialQueue.o: BinomialQueue.cpp BinomialQueue.h
	g++ -g -Wall -std=c++11 -c BinomialQueue.cpp
BNode.o: BNode.cpp BNode.h
	g++ -g -Wall -std=c++11 -c BNode.cpp
clean:
	rm *.o lab9
