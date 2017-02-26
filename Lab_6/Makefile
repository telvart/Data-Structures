lab6: main.o Test.o
	g++ -g -Wall -std=c++11 -o lab6 main.o
main.o: main.cpp Test.h
	g++ -g -Wall -std=c++11 -c main.cpp
Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp
clean:
	rm *.o lab6
