skewheap: main.o SkewHeap.o SHNode.o
	g++ -g -Wall -std=c++11 -o skewheap main.o SkewHeap.o SHNode.o
main.o: main.cpp SkewHeap.cpp SkewHeap.h SHNode.cpp SHNode.h
	g++ -g -Wall -std=c++11 -c main.cpp
SkewHeap.o: SkewHeap.cpp SkewHeap.h SHNode.cpp SHNode.h
	g++ -g -Wall -std=c++11 -c SkewHeap.cpp
SHNode.o: SHNode.cpp SHNode.h
	g++ -g -Wall -std=c++11 -c SHNode.cpp
clean:
	rm *.o skewheap
