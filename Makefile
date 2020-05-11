main.o : main.cpp
	g++ -c main.cpp

main : main.o
	g++ main.o -o main

arbre_exe : arbre.h
	g++ arbre.h -o arbre_exe

noeud_exe : noeud.h
	g++ noeud.h -o noeud_exe

run_tests.o : run_tests.cpp
	 g++ -c run_tests.cpp -o run_tests.o -I googletest-release-1.10.0/googletest/include/ -std=c++11

run_tests : run_tests.o
	g++ -o run_tests run_tests.o googletest-release-1.10.0/lib/libgtest.a googletest-release-1.10.0/lib/libgtest_main.a