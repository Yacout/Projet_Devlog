#include "noeud.h"
#include <vector>
using namespace std;
#if ! defined(ARBRE_H)
#define ARBRE_H



class arbre{

	//méthodes
public : 
	arbre(int nbrvar); 
	arbre(const arbre& arbre_copie); //constructeur à partir d'un arbre
	arbre(int nbrvar,int dummyfacor); //Dummy constructor
	arbre(noeud* noeudf, int nbrvar); // Constructeur de l'arbre fille 
	~arbre(); //destructeur
	void calcul_fitness(const vector<vector<bool>> data); 
	arbre* creer_fille();
	int fitness_;

	//attributs
private : 
	noeud* noeud1_; //1er noeud de l'arbre
	noeud** liste_noeuds_ ; // une liste des pointeurs des noeuds sans ordre précis
	int nbr_noeuds_; //Nombre de noeuds dans l'arbre
	void mutation_ajout();
	void mutation_deletion();
	void mutation_substitution();
	void mutation_random(); //Choix aléatoire d'une des trois mutations
	void compter_noeuds(); //Compte le nombre de noeuds dans l'arbre
	void lister_noeuds(); //Liste les noeuds de l'arbre dans liste_noeuds_
	void cree_arbre_random(); //Crée un arbre aléatoire avec 5 noeuds
	int nbrvar_;

};
#endif
