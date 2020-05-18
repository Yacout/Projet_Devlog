#include "gtest/gtest.h"
#include "noeud.cpp"
#include <iostream>
TEST(GTestTests, ExampleTest) {
	const char* test_exemple();

	bool list[2];
	list[0] = 1;
	list[1] = 0;

	bool F = 0;
	bool T = 1;

	noeud noeud1(3, 1);
	noeud noeud2(1, F, T);
	noeud noeud3(1, true, 0);
	noeud noeud4(2, &noeud1, &noeud2);
	noeud noeud5(1, &noeud4, &noeud3);
	EXPECT_EQ(noeud5.compute(list), 1);
};


