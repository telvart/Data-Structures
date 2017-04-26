lab11: main.o MSTSolver.o Test.o Timer.o
	g++ -g -Wall -std=c++11 -o lab11 main.o MSTSolver.o Test.o Timer.o

MSTSolver.o: MSTSolver.cpp MSTSolver.h
	g++ -g -std=c++11 -c MSTSolver.cpp

Test.o: Test.cpp Test.h
	g++ -g -Wall -std=c++11 -c Test.cpp

Timer.o: Timer.cpp Timer.h
	g++ -g -Wall -std=c++11 -c Timer.cpp

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm *.o lab11
