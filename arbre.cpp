#include "arbre.h"
#include <random>
#include <stdlib.h> 
#include <cstring> 

using namespace std;

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

//Dummy constructor pour les tests

arbre::arbre(int dummyfacor){
	liste_noeuds_=new noeud*[5];
	liste_noeuds_[0] = new noeud(1,2,3); //Noeud AND entre variable 2 et 3
	liste_noeuds_[1] = new noeud(1,1,5); //Noeud AND entre variable 1 et 5
	liste_noeuds_[2] = new noeud(2,1,liste_noeuds_[0]); //Noeud OR entre variable 1 et noeud 0
	liste_noeuds_[3] = new noeud(3, liste_noeuds_[1]); //Noeud NOT sur noeud 1
	liste_noeuds_[4] = new noeud(1,liste_noeuds_[2],liste_noeuds_[3]); //Noeud AND entre noeud 2 et 3
	nbr_noeuds_ = 5;
	noeud1_ = liste_noeuds_[4];
}


void arbre::calcul_fitness(const vector<vector<bool>> data) {
	int f=0;
	for(int i=0; i<data.size(); i++){ 
		int diff=noeud1_->compute(data[i]) -data[i][data[i].size()-1]; //Conversion implicite de bool à int
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

    random_device rd;  
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3);
    
    if (dis(gen)==1) {
    	mutation_ajout();
    } else if (dis(gen)==2){
    	mutation_deletion();
    } else{
    	mutation_substitution();
    }

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


