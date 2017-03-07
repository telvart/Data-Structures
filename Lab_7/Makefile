lab7: main.o MinMaxHeap.o
	g++ -g -Wall -std=c++11 -o lab7 main.o MinMaxHeap.o

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

MinMaxHeap.o: MinMaxHeap.cpp MinMaxHeap.h
	g++ -g -Wall -std=c++11 -c MinMaxHeap.cpp
	
clean:
	rm *.o lab7
