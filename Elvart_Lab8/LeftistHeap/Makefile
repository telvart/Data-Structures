leftistheap: main.o LeftistHeap.o LHNode.o
	g++ -g -Wall -std=c++11 -o leftistheap main.o LeftistHeap.o LHNode.o
main.o: main.cpp LeftistHeap.h LeftistHeap.cpp LHNode.h LHNode.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
LeftistHeap.o: LeftistHeap.cpp LeftistHeap.h LHNode.cpp LHNode.h
	g++ -g -Wall -std=c++11 -c LeftistHeap.cpp
LHNode.o: LHNode.cpp LHNode.h
	g++ -g -Wall -std=c++11 -c LHNode.cpp
clean:
	rm *.o leftistheap
