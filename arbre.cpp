#include "arbre.h"
#include <random>
#include <stdlib.h> 
#include <cstring> 



arbre::arbre() {
	//Créer arbre
	cree_arbre_random();

}

//Constructeur de copie. Supprimer si non utilisé (mais pas du .h pour éviter que C++ esssaye d'en faire un par lui même)

arbre::arbre(const arbre& arbre_copie) {
	fitness_ = arbre_copie.fitness_;
	memcpy(liste_noeuds_, arbre_copie.liste_noeuds_, arbre_copie.nbr_noeuds_); //Vieille fonction, ne plait pas au compileur
	nbr_noeuds_ = arbre_copie.nbr_noeuds_;
	noeud1_ = arbre_copie.noeud1_;
}




void arbre::calcul_fitness(const bool* data) {
	int f=0;
	for(int i=0; i<data.size(); i++){ // data est un tableau, n'a pas de méthode size.
	//Changer le type de data pour un vector dans la déclaration pour pouvoir utiliser size()
		int diff=liste_noeuds_[i]->compute() -data[i]; //Conversion implicite de bool à int
		f=f+ diff*diff; //Il faut fournir la liste de données à compute (liste qui correspond à une ligne du tableau)
	}
	fitness_=-f;
}

void arbre::cree_arbre_random() {
	//Crée un arbre aléatoire avec 5 opérateurs
	//Création d'un arbre avec un opérateur puis 4 mutations ajout successives

	noeud1_ = new noeud(); //Noeud créé dans le heap

	//Ajouter les une ou deux variables en dessous de l'opérateur dans le tableau
	for (int i = 1; i < 5; ++i) {
		//Sélection d'un noeud random où faire l'ajout
		mutation_ajout(); //Dépend de comment marche les noeuds
	}
	compter_noeuds();
	//Il faut ajouter les noeuds à liste_noeuds_
	
}



void arbre::compter_noeuds() {
        nbr_noeuds_ = 1;
        int* ret = new int;
        noeud1_->size(*ret);
        nbr_noeuds_ = *ret;

        delete [] ret;
        ret = NULL;

}


void arbre::mutation_random() {

}

void arbre::mutation_ajout() {
	
}

void arbre::mutation_deletion() {
	int numnoeud = rand() % nbr_noeuds_;
	if (liste_noeuds_[numnoeud]->nb_aretes() == 1) {
		delete[](liste_noeuds_[numnoeud]->aretes()[0]);
	}else if(liste_noeuds_[numnoeud]->nb_aretes() == 2){
		int monrand = rand() % 2;
		delete[](liste_noeuds_[numnoeud]->aretes()[monrand]);
	}
}

void arbre::mutation_substitution() {
	//Choix du noeud à modifier
	int numnoeud = rand() % nbr_noeuds_;
	//Choix du nouveau type d'opérateur du noeud
	int monrand = rand() % 100;
	int newop;
	switch (liste_noeuds_[numnoeud]->op())
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

arbre::~arbre(){
	for(int i=0; i<nbr_noeuds_;i++){
		delete[] liste_noeuds_[i];
	}
	delete[] liste_noeuds_;
}


