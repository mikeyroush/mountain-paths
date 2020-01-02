all: Main

Main: mountainpaths.o functions.o
	g++ mountainpaths.o functions.o -o Main

mountainpaths.o: mountainpaths.cpp
	g++ -std=c++11 -c mountainpaths.cpp

functions.o: functions.h functions.cpp
	g++ -std=c++11 -c functions.h functions.cpp

clean:
	rm *.o Main
