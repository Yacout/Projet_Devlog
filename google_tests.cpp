#include "gtest/gtest.h"
#include "noeud.h"
#include <iostream>

/*TEST(GTestTests, TestSize){

	bool F = 0;
	bool T = 1;

	noeud** liste_noeud = new noeud*[5];

	liste_noeud[0] = new noeud(1);
	liste_noeud[1] = new noeud(1, F, T);
	liste_noeud[2] = new noeud(1, true, 0);
	liste_noeud[3] = new noeud(2, liste_noeud[0], liste_noeud[1]);
	liste_noeud[4] = new noeud(1, liste_noeud[2], liste_noeud[3]);

	int s=0;
	liste_noeud[4]->size(s);

	EXPECT_EQ(s, 5);
};*/

TEST(GTestTests, TestListe){

	bool F = 0;
	bool T = 1;

	noeud noeud1(1);
	noeud noeud2(1, F, T);
	noeud noeud3(1, true, 0);
	noeud noeud4(2, &noeud1, &noeud2);
	noeud noeud5(1, &noeud4, &noeud3);
	noeud defaut(1, F, F);
	int s=0;
	noeud5.size(s);
	noeud* arr2[s];
	
	for(int i=0; i<s;i++){		//remplissage du tableau de pointeurs, pour savoir quelles parties du tableau ont été utilisés
		arr2[i]=&defaut;
	}

	EXPECT_EQ(arr2[0],&defaut);
	EXPECT_EQ(arr2[1],&defaut);
	EXPECT_EQ(arr2[2],&defaut);
	EXPECT_EQ(arr2[3],&defaut);
	EXPECT_EQ(arr2[4],&defaut);
	
	noeud5.liste(arr2,&defaut);			
	
	EXPECT_EQ(arr2[0],&noeud5);
	EXPECT_EQ(arr2[1],&noeud4);
	EXPECT_EQ(arr2[2],&noeud1);
	EXPECT_EQ(arr2[3],&noeud2);
	EXPECT_EQ(arr2[4],&noeud3);
	
};

TEST(GTestTests, TestOpMut){

	noeud noeud1(1, true, false);
	noeud1.op(2);

	EXPECT_EQ(noeud1.op(), 2);
};
