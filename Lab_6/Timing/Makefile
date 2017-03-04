timing: main.o Test.o Timer.o
	g++ -g -Wall -std=c++11 -o timing main.o Test.o Timer.o
main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp
Timer.o: Timer.cpp Timer.h
	g++ -g -Wall -std=c++11 -c Timer.cpp
clean:
	rm *.o timing
