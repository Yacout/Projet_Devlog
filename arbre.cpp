#include "arbre.h"
#include <random>
#include <stdlib.h> 
#include <cstring> 



arbre::arbre() {
	//Cr�er arbre
	cree_arbre_random();

}

//Constructeur de copie. Supprimer si non utilis� (mais pas du .h pour �viter que C++ esssaye d'en faire un par lui m�me)

arbre::arbre(const arbre& arbre_copie) {
	fitness_ = arbre_copie.fitness_;
	memcpy(liste_noeuds_, arbre_copie.liste_noeuds_, arbre_copie.nbr_noeuds_); //Vieille fonction, ne plait pas au compileur
	nbr_noeuds_ = arbre_copie.nbr_noeuds_;
	noeud1_ = arbre_copie.noeud1_;
}




void arbre::calcul_fitness(const bool* data) {
	int f=0;
	for(int i=0; i<data.size(); i++){ // data est un tableau, n'a pas de m�thode size.
	//Changer le type de data pour un vector dans la d�claration pour pouvoir utiliser size()
		f=f+ (liste_noeuds_[i].compute() -data[i]) * (liste_noeuds_[i].compute() - data[i]); //Il faut fournir la liste de donn�es � compute (liste qui correspond � une ligne du tableau)
	}
	fitness_=-f;
}

void arbre::cree_arbre_random() {
	//Cr�e un arbre al�atoire avec 5 op�rateurs
	//Cr�ation d'un arbre avec un op�rateur puis 4 mutations ajout successives

	noeud1_ = new noeud(); //Noeud cr�� dans le heap

	//Ajouter les une ou deux variables en dessous de l'op�rateur dans le tableau
	for (int i = 1; i < 5; ++i) {
		//S�lection d'un noeud random o� faire l'ajout
		mutation_ajout(); //D�pend de comment marche les noeuds
	}
	compter_noeuds();
	
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
	if (liste_noeuds_[numnoeud].nb_aretes() == 1) {
		delete[](liste_noeuds_[numnoeud].aretes()[0]);
	}else if(liste_noeuds_[numnoeud].nb_aretes() == 2){
		int monrand = rand() % 2;
		delete[](liste_noeuds_[numnoeud].aretes()[monrand]);
	}
}

void arbre::mutation_substitution() {
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

arbre::~arbre(){
}


