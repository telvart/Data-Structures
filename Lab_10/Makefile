lab10: main.o MSTSolver.o
	g++ -g -Wall -std=c++11 -o lab10 main.o MSTSolver.o
main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
MSTSovler.o: MSTSolver.cpp MSTSolver.h
	g++ -g -Wall -std=c++11 -c MSTSovler.cpp
clean:
	rm *.o lab10
