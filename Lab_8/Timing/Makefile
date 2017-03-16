timing: main.o Test.o SkewHeap.o LeftistHeap.o SHNode.o LHNode.o Timer.o
	g++ -g -Wall -std=c++11 -o timing main.o Test.o SkewHeap.o LeftistHeap.o SHNode.o LHNode.o Timer.o
main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp
SkewHeap.o: SkewHeap.cpp SkewHeap.h
	g++ -g -Wall -std=c++11 -c SkewHeap.cpp
LeftistHeap.o: LeftistHeap.cpp LeftistHeap.h
	g++ -g -Wall -std=c++11 -c LeftistHeap.cpp
SHNode.o: SHNode.cpp SHNode.h
	g++ -g -Wall -std=c++11 -c SHNode.cpp
LHNode.o: LHNode.cpp LHNode.h
	g++ -g -Wall -std=c++11 -c LHNode.cpp
Timer.o: Timer.cpp Timer.h
	g++ -g -Wall -std=c++11 -c Timer.cpp
clean:
	rm *.o timing
