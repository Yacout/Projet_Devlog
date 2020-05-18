CXXFLAGS= -Wall

MyTest: google_tests.o
	g++ $(CXXFLAGS) -o run_tests google_tests.o googletest-release-1.10.0/build/lib/libgtest.a googletest-release-1.10.0/build/lib/libgtest_main.a -pthread

google_tests.o: google_tests.cpp 
	g++ $(CXXFLAGS) -c google_tests.cpp -o google_tests.o -Igoogletest-release-1.10.0/googletest/include/ -std=c++11 

clean:
	rm google_tests.o run_tests 
