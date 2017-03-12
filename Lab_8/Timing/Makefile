timing: main.o Test.o
	g++ -g -Wall -std=c++11 -o timing main.o Test.o
main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp
clean:
	rm *.o timing
