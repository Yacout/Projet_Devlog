#include "arbre.h"
#include "noeud.h"
#include <random>

arbre::arbre() {
	fitness_ = -1000;
}

arbre::arbre(bool* d) {
	data_ = d;
	//Cr�er arbre
	cree_arbre_random
	
	
	calcul_fitness();

}

arbre::arbre(const arbre arbre_copie) {
	fitness_ = arbre_copie.fitness_;
	data_ = arbre_copie.data_;
	memcpy(liste_noeuds_, arbre_copie.liste_noeuds_, arbre_copie.longueur_liste_);
	longueur_liste_ = arbre_copie.longueur_liste_;
	noeud1_ = arbre_copie.noeud1_;
}




arbre::calcul_fitness() {
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

arbre::compter_noeuds() {
	longueur_liste_ = 1;
	pacourir_noeud(noeud1_);
}

arbre::parcourir_noeud(noeud n) {
	//Regarde le noeud donn�e, compte le nombre de noeuds affili�s, lance parcourir_noeud() sur chacun des affili�s
}

arbre::mutation_random() {

}

arbre::mutation_ajout() {

}

arbre::mutation_deletion() {

}

arbre::mutation_substitution() {

}