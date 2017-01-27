lab1: main.o
	g++ -g -Wall -std=c++11 -o lab1 main.o

main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm *.o lab1
