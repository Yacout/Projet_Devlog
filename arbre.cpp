#include "arbre.h"
#include "noeud.cpp"
#include <random>
#include <stdlib.h>  



arbre::arbre() {
	//Créer arbre
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
	//Crée un arbre aléatoire avec 5 opérateurs
	//Création d'un arbre avec un opérateur puis 4 mutations ajout successives

	noeud1_ = new noeud();

	//Ajouter les une ou deux variables en dessous de l'opérateur dans le tableau
	for (int i = 1; i < 5; ++i) {
		//Sélection d'un noeud random où faire l'ajout
		mutation_ajout(); //Dépend de comment marche les noeuds
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
	//Choix du noeud à modifier
	int numnoeud = rand() % nbr_noeuds_;
	//Choix du nouveau type d'opérateur du noeud
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



