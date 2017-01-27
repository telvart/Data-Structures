lab2: main.o OpenHashTable.o
	g++ -g -Wall -std=c++11 -o lab2 main.o OpenHashTable.o

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

OpenHashTable.o: OpenHashTable.cpp OpenHashTable.h
	g++ -g -Wall -std=c++11 -c OpenHashTable.cpp

clean:
	rm *.o lab2
