#include "arbre.h"
#include <random>
#include <stdlib.h> 
#include <cstring> 

using namespace std;

arbre::arbre(int nbrvar) {
	nbrvar_=nbrvar;
	cree_arbre_random();
}

//Constructeur de copie. Supprimer si non utilisÃ© (mais pas du .h pour Ã©viter que C++ esssaye d'en faire un par lui mÃªme)

arbre::arbre(const arbre& arbre_copie) {
	fitness_ = arbre_copie.fitness_;
	memcpy(liste_noeuds_, arbre_copie.liste_noeuds_, arbre_copie.nbr_noeuds_); //Vieille fonction, ne plait pas au compileur
	nbr_noeuds_ = arbre_copie.nbr_noeuds_;
	noeud1_ = arbre_copie.noeud1_;
	nbrvar_=arbre_copie.nbrvar_;
}

//Dummy constructor pour les tests

arbre::arbre(int nbrvar, int dummyfacor){
	liste_noeuds_=new noeud*[5];
	liste_noeuds_[0] = new noeud(1,2,3); //Noeud AND entre variable 2 et 3
	liste_noeuds_[1] = new noeud(1,1,5); //Noeud AND entre variable 1 et 5
	liste_noeuds_[2] = new noeud(2,1,liste_noeuds_[0]); //Noeud OR entre variable 1 et noeud 0
	liste_noeuds_[3] = new noeud( liste_noeuds_[1]); //Noeud NOT sur noeud 1
	liste_noeuds_[4] = new noeud(1,liste_noeuds_[2],liste_noeuds_[3]); //Noeud AND entre noeud 2 et 3
	nbr_noeuds_ = 5;
	noeud1_ = liste_noeuds_[4];
	nbrvar_=nbrvar;
}


void arbre::calcul_fitness(const vector<vector<bool>> data) {
	int f=0;
	for(unsigned i=0; i<data.size(); i++){ 
		int diff=noeud1_->compute(data[i]) -data[i][data[i].size()-1]; //Conversion implicite de bool Ã  int
		f=f+ diff*diff; //Il faut fournir la liste de donnÃ©es Ã  compute (liste qui correspond Ã  une ligne du tableau)
	}
	fitness_=-f;
}

void arbre::cree_arbre_random() {
	//Crée un arbre aléatoire avec 5 opérateurs
	//Création d'un arbre avec un opérateur puis 4 mutations ajout successives
	
	int operation = rand() %3+1;
	if(operation==3){
		int var = rand() %nbrvar_ ;
		noeud1_ = new noeud(var);
	} else {
		int var1 = rand() %nbrvar_ ;
		int var2 = rand() %nbrvar_ ;
		noeud1_ = new noeud(operation, var1, var2);
	}
	nbr_noeuds_=1;

	//Ajouter les une ou deux variables en dessous de l'opérateur dans le tableau
	for (int i = 1; i < 5; ++i) {
		//Sélection d'un noeud random où faire l'ajout
		mutation_ajout(); //Dépend de comment marche les noeuds
		nbr_noeuds_++;
	}
	
	lister_noeuds();
	
}


arbre::arbre(noeud* noeudf){
	noeud1_ = noeudf;
	compter_noeuds(); 
	lister_noeuds();
	mutation_random();
	
	delete [] liste_noeuds_;
	liste_noeuds_ = NULL;
	
	compter_noeuds();
	lister_noeuds();
	
}

arbre arbre::creer_fille(){
	noeud* noeudf = new noeud(noeud1_);
	arbre arbrette(noeudf);
	
	return arbrette;
}


void arbre::lister_noeuds(){
	liste_noeuds_ = new noeud*[nbr_noeuds_];
	noeud defaut(1, false, false); //Necessaire à l'utilisation de liste()...
	for (int i=0; i<nbr_noeuds_;i++){
		liste_noeuds_[i]=&defaut;
	}
	noeud1_->liste(liste_noeuds_,&defaut);
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
	noeud* raccord;
	int raccordvar;
	bool israccordvar=false;
	int numnoeud = rand() % nbr_noeuds_;
	int monrand = rand() % 2;
	int nbrvar=liste_noeuds_[numnoeud]->nb_var();
	int nbrarete=liste_noeuds_[numnoeud]->nb_aretes();
	
	if(liste_noeuds_[numnoeud]->op()==3){ //Si le noeud sÃ©lectionnÃ© est un NOT
		if (nbrvar!=0){
			raccordvar=liste_noeuds_[numnoeud] -> var()[0];
			israccordvar=true;
		}else{
			raccord=liste_noeuds_[numnoeud] -> aretes()[0];
		}
	}else{ //Si le noeud sÃ©lectionnÃ© est un AND ou un OR
		if(nbrvar==2){
			raccordvar=liste_noeuds_[numnoeud] -> var()[monrand];
			israccordvar=true;
		} else if (nbrarete==2){
			raccord=liste_noeuds_[numnoeud] -> aretes()[monrand];
		} else {
			if (monrand==0){
				raccordvar=liste_noeuds_[numnoeud] -> var()[0];
				israccordvar=true;
			} else {
				raccord = liste_noeuds_[numnoeud] -> aretes()[0];
			}
		}
	}
	monrand = rand() % 3 + 1;
	noeud* nvnoeud;
	if (monrand==3){
		nvnoeud = (israccordvar ? new noeud(raccordvar) : new noeud(raccord));
	} else {
		int varcomp = rand() % nbrvar_;
		nvnoeud = (israccordvar ? new noeud(monrand,raccordvar,varcomp) : new noeud(monrand,raccord,varcomp));
	}
 	liste_noeuds_[nbr_noeuds_] = nvnoeud; //On suppose qu'il reste au moins une place dans le tableau liste_noeuds_ (cas normal)
	liste_noeuds_[numnoeud] -> aretes()[nbrarete]=nvnoeud;
}

void arbre::mutation_deletion() {
	int numnoeud = rand() % nbr_noeuds_;
	if(liste_noeuds_[numnoeud]->nb_aretes() >= 1){
		if (liste_noeuds_[numnoeud]->nb_aretes() == 1) {
			delete[](liste_noeuds_[numnoeud]->aretes()[0]); //Pas possible car les getters sont const, obviously
		}else{
			int monrand = rand() % 2;
			delete[](liste_noeuds_[numnoeud]->aretes()[monrand]); //Pas possible car les getters sont const, obviously
		}
		int monrand = rand() % nbrvar_;
		liste_noeuds_[numnoeud]->var()[liste_noeuds_[numnoeud]->nb_var()]=monrand; //Pas possible car les getters sont const, obviously
	}
}

void arbre::mutation_substitution() {
	//Choix du noeud Ã  modifier
	int numnoeud = rand() % nbr_noeuds_;
	//Choix du nouveau type d'opÃ©rateur du noeud
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


