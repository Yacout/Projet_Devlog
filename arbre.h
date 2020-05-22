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
	~arbre(); //destructeur
	void calcul_fitness(const vector<vector<bool>> data); 
	arbre creer_fille();
	int fitness_;


	//attributs
private : 
	noeud* noeud1_; //1er noeud de l'arbre
	noeud** liste_noeuds_ ; // une liste des pointeurs des noeuds sans ordre précis
	int nbr_noeuds_;
	void mutation_ajout();
	void mutation_deletion();
	void mutation_substitution();
	void mutation_random();
	void compter_noeuds();
	void cree_arbre_random();
	int nbrvar_;



};
#endif
