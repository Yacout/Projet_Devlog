CXXFLAGS = Wall
objects = run_tests.o noeud.o tests.o

all: run_tests

run_tests: $(objects)
	g++ -o run_tests $(objects) 

run_tests.o: run_tests.cpp
	g++ -o run_tests.o -c run_tests.cpp 

noeud.o: noeud.cpp noeud.h
	g++ -c -o noeud.o noeud.cpp

tests.o: tests.cpp tests.h
	g++ -c -o tests.o tests.cpp

check:
	./run_tests

clean:
	rm $(objects)
