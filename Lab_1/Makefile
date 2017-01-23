lab1: main.o DoubleLinkedList.o Node.o
	g++ -g -Wall -std=c++11 -o lab1 main.o DoubleLinkedList.o Node.o

main.o: main.cpp DoubleLinkedList.h
	g++ -g -Wall -std=c++11 -c main.cpp

DoubleLinkedList.o: DoubleLinkedList.cpp DoubleLinkedList.h Node.h
	g++ -g -Wall -std=c++11 -c DoubleLinkedList.cpp

Node.o: Node.cpp Node.h
	g++ -g -Wall -std=c++11 -c Node.cpp

clean:
	rm *.o lab1
