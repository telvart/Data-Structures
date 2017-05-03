lab12: main.o SPSolver.o
	g++ -g -Wall -std=c++11 -o lab12 main.o SPSolver.o
main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
SPSolver.o: SPSolver.cpp SPSolver.h
	g++ -g -std=c++11 -c SPSolver.cpp
clean:
	rm *.o lab12
