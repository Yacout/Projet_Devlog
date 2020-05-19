#include "noeud.h"
#if ! defined(ARBRE_H)
#define ARBRE_H

class arbre{

	//méthodes
public : 
	arbre(); //constructeur par défaut
	arbre(const arbre& arbre_copie); //constructeur à partir d'un arbre
	~arbre(); //destructeur
	void calcul_fitness(const bool* data); 
	arbre creer_fille();
	int fitness_;


	//attributs
private : 
	noeud* noeud1_; //1er noeud de l'arbre
	noeud* liste_noeuds_ ; // une liste de noeuds sans ordre précis
	int nbr_noeuds_;
	void mutation_ajout();
	void mutation_deletion();
	void mutation_substitution();
	void mutation_random();
	void compter_noeuds();
	void cree_arbre_random();



};
#endif
