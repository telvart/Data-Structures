lab10: main.o MSTSolver.o
	g++ -g -Wall -std=c++11 -o lab10 main.o MSTSolver.o

MSTSolver.o: MSTSolver.cpp MSTSolver.h
	g++ -g -std=c++11 -c MSTSolver.cpp

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm *.o lab10
