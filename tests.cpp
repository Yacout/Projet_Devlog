#include "./tests.h"
#include "./noeud.h"

const char* test_exemple(){

	bool* list = new bool[2];
	list[0] = 1;
	list[1] = 0;

	bool F = 0;
	bool T = 1;

	noeud noeud1(3, 1);
	noeud noeud2(1, F, T);
	noeud noeud3(1, true, 0);
	noeud noeud4(2, &noeud1, &noeud2);
	noeud noeud5(1, &noeud4, &noeud3);

	if (noeud5.compute(list) == true){
		return "PASS";
	} else {
		return "FAIL";
	}
}
