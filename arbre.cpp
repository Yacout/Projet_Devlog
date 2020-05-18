#include "arbre.h"
#include "noeud.cpp"
#include <random>
#include <stdlib.h>  



arbre::arbre() {
	//Cr�er arbre
	cree_arbre_random()

}

arbre::arbre(const arbre arbre_copie) {
	fitness_ = arbre_copie.fitness_;
	memcpy(liste_noeuds_, arbre_copie.liste_noeuds_, arbre_copie.nbr_noeuds_);
	nbr_noeuds_ = arbre_copie.nbr_noeuds_;
	noeud1_ = arbre_copie.noeud1_;
}




arbre::calcul_fitness(const bool* data) {
	fitness_ = -10;
}

arbre::cree_arbre_random() {
	//Cr�e un arbre al�atoire avec 5 op�rateurs
	//Cr�ation d'un arbre avec un op�rateur puis 4 mutations ajout successives

	noeud1_ = new noeud();

	//Ajouter les une ou deux variables en dessous de l'op�rateur dans le tableau
	for (int i = 1; i < 5; ++i) {
		//S�lection d'un noeud random o� faire l'ajout
		mutation_ajout(); //D�pend de comment marche les noeuds
	}
	compter_noeud();
	
}

void arbre::compter_noeuds() {
        nbr_noeuds_ = 1;
        int* ret = new int;
        noeud1_.size(ret);
        nbr_noeuds_ = ret;

        delete [] ret;
        ret = NULL;

}


arbre::mutation_random() {

}

arbre::mutation_ajout() {
	
}

arbre::mutation_deletion() {

}

arbre::mutation_substitution() {
	//Choix du noeud � modifier
	int numnoeud = rand() % nbr_noeuds_;
	//Choix du nouveau type d'op�rateur du noeud
	int monrand = rand() % 100;
	int newop;
	switch (liste_noeuds_[numnoeud].op())
	{
	case 1:
		if (monrand > 49) {
			newop = 2;
		}
		else {
			newop = 3;
		}
	case 2:
		if (monrand > 49) {
			newop = 1;
		}
		else {
			newop = 3;
		}
	default:
		if (monrand > 49) {
			newop = 1;
		}
		else {
			newop = 2;
		}
		break;
	}


	//APPEL DES MODIFIERS DU NOEUD
}



