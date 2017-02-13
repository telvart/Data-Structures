lab4: main.o ClosedHashTable.o Bucket.o OpenHashTable.o Timer.o Test.o
	g++ -g -Wall -std=c++11 -o lab4 main.o ClosedHashTable.o Bucket.o OpenHashTable.o Timer.o Test.o

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

ClosedHashTable.o: ClosedHashTable.cpp ClosedHashTable.h Bucket.cpp Bucket.h
	g++ -g -Wall -std=c++11 -c ClosedHashTable.cpp

Bucket.o: Bucket.cpp Bucket.h
	g++ -g -Wall -std=c++11 -c Bucket.cpp

OpenHashTable.o: OpenHashTable.cpp OpenHashTable.h
	g++ -g -Wall -std=c++11 -c OpenHashTable.cpp

Timer.o: Timer.cpp Timer.h
	g++ -g -Wall -std=c++11 -c Timer.cpp

Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp

clean:
	rm *.o lab4
