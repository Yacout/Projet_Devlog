CXXFLAGS= -Wall
objects = noeud.o google_tests.o

all: run_tests

run_tests: $(objects)
	g++ $(CXXFLAGS) -o run_tests $(objects) googletest-release-1.10.0/build/lib/libgtest.a googletest-release-1.10.0/build/lib/libgtest_main.a -pthread

noeud.o: noeud.cpp noeud.h
	g++ $(CXXFLAGS) -c -o noeud.o noeud.cpp

google_tests.o: google_tests.cpp 
	g++ $(CXXFLAGS) -c google_tests.cpp -o google_tests.o -Igoogletest-release-1.10.0/googletest/include/ -std=c++11 

check:
	./run_tests

clean:
	rm $(objects) 
