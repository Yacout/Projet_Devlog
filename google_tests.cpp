#include "gtest/gtest.h"
#include "arbre.h"
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

	int s=0;
	liste_noeud[4]->size(s);
	noeud* arr2[s];
	
	liste_noeud[4]->liste(arr2);			
	
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


<<<<<<< HEAD
TEST(GTestTests, TestFitness){
	std::vector<bool> l1{0, 0, 0, 0, 1, 0 };

	std::vector<bool> l2{0,1,1,1,0,1};

	std::vector<bool> l3{1,1,0,1,0,0};

	std::vector<vector<bool>> test{l1, l2, l3};
		
	arbre* tree = new arbre(1,5);

	tree->calcul_fitness(test);

	EXPECT_EQ(tree->fitness_,5);

};






=======
TEST(GTestTests, TestMutAjout){

	noeud** liste_noeud = new noeud*[1];
	liste_noeud[0] = new noeud(1);
	
	arbre arbretest(5, 1);
	arbretest.mutation_ajout();
	
	
	

}
>>>>>>> 6e4a0d97e379495619db5f2f332e187610d650de



