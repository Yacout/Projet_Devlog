#include "gtest/gtest.h"
#include "noeud.h"
#include <vector>
#include <iostream>

TEST(GTestTests, ExampleTest){

	std::vector<bool> list(2);
	list[0] = 1;
	list[1] = 0;

	bool F = 0;
	bool T = 1;

	noeud** liste_noeud = new noeud*[5];

	liste_noeud[0] = new noeud(1);
	liste_noeud[1] = new noeud(1, F, T);
	liste_noeud[2] = new noeud(1, true, 0);
	liste_noeud[3] = new noeud(2, liste_noeud[0], liste_noeud[1]);
	liste_noeud[4] = new noeud(1, liste_noeud[2], liste_noeud[3]);

	EXPECT_EQ(liste_noeud[4]->compute(list), 1);

	delete liste_noeud[4];
	delete[] liste_noeud;
};

TEST(GTestTests, TestSize){

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

	delete liste_noeud[4];
	delete[] liste_noeud;
};

TEST(GTestTests, TestListe){

	bool F = 0;
	bool T = 1;
	
	noeud** liste_noeud = new noeud*[5];

	liste_noeud[0] = new noeud(1);
	liste_noeud[1] = new noeud(1, F, T);
	liste_noeud[2] = new noeud(1, true, 0);
	liste_noeud[3] = new noeud(2, liste_noeud[0], liste_noeud[1]);
	liste_noeud[4] = new noeud(1, liste_noeud[2], liste_noeud[3]);

	noeud defaut(1, F, F);
	int s=0;
	liste_noeud[4]->size(s);
	noeud* arr2[s];
	
	for(int i=0; i<s;i++){		//remplissage du tableau de pointeurs, pour savoir quelles parties du tableau ont été utilisés
		arr2[i]=&defaut;
	}

	EXPECT_EQ(arr2[0],&defaut);
	EXPECT_EQ(arr2[1],&defaut);
	EXPECT_EQ(arr2[2],&defaut);
	EXPECT_EQ(arr2[3],&defaut);
	EXPECT_EQ(arr2[4],&defaut);
	
	liste_noeud[4]->liste(arr2,&defaut);			
	
	EXPECT_EQ(arr2[0],liste_noeud[4]);
	EXPECT_EQ(arr2[1],liste_noeud[2]);
	EXPECT_EQ(arr2[2],liste_noeud[3]);
	EXPECT_EQ(arr2[3],liste_noeud[0]);
	EXPECT_EQ(arr2[4],liste_noeud[1]);
	
	delete liste_noeud[4];
	delete[] liste_noeud;
};

TEST(GTestTests, TestCopie){

	std::vector<bool> list(2);
	list[0] = 1;
	list[1] = 0;

	bool F = 0;
	bool T = 1;

	noeud** liste_noeud = new noeud*[5];

	liste_noeud[0] = new noeud(1);
	liste_noeud[1] = new noeud(1, F, T);
	liste_noeud[2] = new noeud(1, true, 0);
	liste_noeud[3] = new noeud(2, liste_noeud[0], liste_noeud[1]);
	liste_noeud[4] = new noeud(1, liste_noeud[2], liste_noeud[3]);

	noeud* copie = new noeud(*liste_noeud[4]);
	std::cout << copie->compute(list) << std::endl;
	EXPECT_EQ(copie->compute(list), 1);
	std::cout << copie->aretes()[0] << std::endl;
	std::cout << liste_noeud[4]->aretes()[0] << std::endl; //Pas les mêmes adresses

	delete liste_noeud[4];
	delete[] liste_noeud;
	delete copie;
};
