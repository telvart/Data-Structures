lab3: main.o ClosedHashTable.o ClosedDoubleHashTable.o Bucket.o
	g++ -g -Wall -std=c++11 -o lab3 main.o ClosedHashTable.o ClosedDoubleHashTable.o Bucket.o

main.o: main.cpp ClosedHashTable.h
	g++ -g -Wall -std=c++11 -c main.cpp

ClosedHashTable.o: ClosedHashTable.cpp ClosedHashTable.h Bucket.h Bucket.cpp
	g++ -g -Wall -std=c++11 -c ClosedHashTable.cpp

ClosedDoubleHashTable.o: ClosedDoubleHashTable.cpp ClosedDoubleHashTable.h Bucket.cpp Bucket.h
	g++ -g -Wall -std=c++11 -c ClosedDoubleHashTable.cpp

Bucket.o: Bucket.cpp Bucket.h
	g++ -g -Wall -std=c++11 -c Bucket.cpp

clean:
	rm *.o lab3
