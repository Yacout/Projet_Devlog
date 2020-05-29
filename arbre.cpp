#include "arbre.h"
#include <random>
#include <stdlib.h> 
#include <cstring>
#include <iostream>

using namespace std;

arbre::arbre(int nbrvar) {
	nbrvar_=nbrvar;
	cree_arbre_random();
}

//Constructeur de copie. Supprimer si non utilisé (mais pas du .h pour éviter que C++ esssaye d'en faire un par lui même)

arbre::arbre(const arbre& arbre_copie) {
	fitness_ = arbre_copie.fitness_;
	memcpy(liste_noeuds_, arbre_copie.liste_noeuds_, arbre_copie.nbr_noeuds_); //Vieille fonction, ne plait pas au compileur
	nbr_noeuds_ = arbre_copie.nbr_noeuds_;
	noeud1_ = arbre_copie.noeud1_;
	nbrvar_=arbre_copie.nbrvar_;
}

//Dummy constructor pour les tests

arbre::arbre(int nbrvar, int dummyfactor){
	liste_noeuds_=new noeud*[5];
	liste_noeuds_[0] = new noeud(1,2,3); //Noeud AND entre variable 2 et 3
	liste_noeuds_[1] = new noeud(1,1,5); //Noeud AND entre variable 1 et 5
	liste_noeuds_[2] = new noeud(2,1,liste_noeuds_[0]); //Noeud OR entre variable 1 et noeud 0
	liste_noeuds_[3] = new noeud(liste_noeuds_[1]); //Noeud NOT sur noeud 1
	liste_noeuds_[4] = new noeud(1,liste_noeuds_[2],liste_noeuds_[3]); //Noeud AND entre noeud 2 et 3
	nbr_noeuds_ = 5;
	noeud1_ = liste_noeuds_[4];
	nbrvar_=nbrvar;
}

arbre::arbre(noeud* noeudf,int nbrvar) {
	noeud1_ = noeudf;
	nbrvar_ = nbrvar;
	compter_noeuds();
	lister_noeuds();
	mutation_random();

	delete[] liste_noeuds_;
	liste_noeuds_ = NULL;

	compter_noeuds();
	lister_noeuds();

}


void arbre::calcul_fitness(const vector<vector<bool>> data) {
	int f=0;
	for(unsigned i=1; i<data.size(); i++){ //La première ligne de data est vide, à skip
		int diff = noeud1_->compute(data[i]) - data[i][data[i].size()-1]; //Conversion implicite de bool à int
		f = f + diff*diff; //Il faut fournir la liste de données à compute (liste qui correspond à une ligne du tableau)

	}
	fitness_=-f;
}

void arbre::cree_arbre_random() {
	//Cr�e un arbre al�atoire avec 5 op�rateurs
	//Cr�ation d'un arbre avec un op�rateur puis 4 mutations ajout successives
	
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
	liste_noeuds_ = new noeud * [5]; //Une liste assez grande pour accueillir tous les noeuds
	liste_noeuds_[0] = noeud1_;

	//Ajouter les une ou deux variables en dessous de l'op�rateur dans le tableau
	for (int i = 1; i < 5; ++i) {
		//S�lection d'un noeud random o� faire l'ajout
		mutation_ajout(); //D�pend de comment marche les noeuds
		nbr_noeuds_++;
        //delete [] liste_noeuds_; //Pas besoin à priori, mutation rajoute automatiquement le noeud 
        //lister_noeuds();
	}
    //delete [] liste_noeuds_; Pas besoin, que des mutations ajout
    //liste_noeuds_ = NULL;
	//lister_noeuds();
	
}




arbre* arbre::creer_fille(){
	noeud* noeudf = new noeud(*noeud1_);
	arbre* arbrette = new arbre(noeudf,nbrvar_);
	
	return arbrette;
}


void arbre::lister_noeuds(){
	liste_noeuds_ = new noeud*[nbr_noeuds_+1]; //Place pour une mutation ajout éventuelle
	noeud1_->liste(liste_noeuds_);
}

void arbre::compter_noeuds() {
        nbr_noeuds_ = 1;
        int* ret = new int;
		*ret = 0;
        noeud1_->size(*ret);
        nbr_noeuds_ = *ret;

        delete ret;
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
	noeud* raccord=nullptr;
	int raccordvar;
	bool israccordvar=false;
	int numnoeud = rand() % nbr_noeuds_;
	int monrand = rand() % 2;
	int nbrvar=liste_noeuds_[numnoeud]->nb_var();
	int nbrarete=liste_noeuds_[numnoeud]->nb_aretes();
	
	if(liste_noeuds_[numnoeud]->op()==3){ //Si le noeud sélectionné est un NOT
		if (nbrvar!=0){
			raccordvar=liste_noeuds_[numnoeud] -> var()[0];
			israccordvar=true;
		}else{
			raccord=liste_noeuds_[numnoeud] -> aretes()[0];
		}
	}else{ //Si le noeud sélectionné est un AND ou un OR
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
	int monrand1 = rand() % 3 + 1;
	noeud* nvnoeud;
	if (monrand1==3){ //Si le nouveau noeud est un NOT
		nvnoeud = (israccordvar ? new noeud(raccordvar) : new noeud(raccord));
	} else {
		int varcomp = rand() % nbrvar_;
		nvnoeud = (israccordvar ? new noeud(monrand1,raccordvar,varcomp) : new noeud(monrand1,varcomp,raccord));
	}
 	liste_noeuds_[nbr_noeuds_] = nvnoeud; //On suppose qu'il reste au moins une place dans le tableau liste_noeuds_ (cas normal)
 	if(israccordvar){
 	    noeud** temp = new noeud*[nbrarete+1];
 	    for(int i=0;i<nbrarete;i++){
 	        temp[i]=liste_noeuds_[numnoeud]->aretes_[i];
 	    }
 	    delete[] liste_noeuds_[numnoeud]->aretes_;
        liste_noeuds_[numnoeud]->aretes_=temp;
        liste_noeuds_[numnoeud]->nb_aretes_=liste_noeuds_[numnoeud]->nb_aretes_+1;
        liste_noeuds_[numnoeud]->nb_var_=liste_noeuds_[numnoeud]->nb_var_-1;
        liste_noeuds_[numnoeud] -> aretes()[nbrarete]=nvnoeud;
    }else if(nbrarete==1){
 	    liste_noeuds_[numnoeud] ->aretes()[0]=nvnoeud;
 	}else{
        liste_noeuds_[numnoeud] ->aretes()[monrand]=nvnoeud;
 	}

}

void arbre::mutation_deletion() {
	int numnoeud = rand() % nbr_noeuds_;
	if(liste_noeuds_[numnoeud]->nb_aretes() >= 1){
		if (liste_noeuds_[numnoeud]->nb_aretes() == 1) {
			delete (liste_noeuds_[numnoeud]->aretes()[0]); //Supression du noeud retiré

			delete[] liste_noeuds_[numnoeud]->aretes_; //Supression du tableau d'arètes car il n'y en a plus
			int* temp = new int[liste_noeuds_[numnoeud]->nb_var_ + 1];
			for (int i = 0; i < liste_noeuds_[numnoeud]->nb_var_; i++) {
				temp[i] = liste_noeuds_[numnoeud]->var_[i];
			}
			delete[]liste_noeuds_[numnoeud]->var_;
			liste_noeuds_[numnoeud]->var_ = temp;
			liste_noeuds_[numnoeud]->nb_var_++; //1 ou deux variables selon s'il s'agit d'un NOT ou non
			liste_noeuds_[numnoeud]->nb_aretes_ = 0; //Plus d'arete

		}else{
			int monrand = rand() % 2;
			delete (liste_noeuds_[numnoeud]->aretes()[monrand]); 

			liste_noeuds_[numnoeud]->var_ = new int[0];
			liste_noeuds_[numnoeud]->nb_var_ = 1; //1 nouvelle variable
			liste_noeuds_[numnoeud]->nb_aretes_ = 1; //Plus qu'une seule arete


		}
		int monrand = rand() % nbrvar_;
		liste_noeuds_[numnoeud]->var()[liste_noeuds_[numnoeud]->nb_var_-1]=monrand; 
	}
}

void arbre::mutation_substitution() {
	//Choix du noeud � modifier
	int numnoeud = rand() % nbr_noeuds_;
	//Choix du nouveau type d'op�rateur du noeud
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
	noeud* noeudm = liste_noeuds_[numnoeud];
	if (noeudm->op_!=3 && newop != 3){ //Si le noeud n'�tait pas un NOT et ne devient pas un NOT
		noeudm -> op_ = newop;
	}else if (noeudm->op_==3){ //Si le noeud �tait un NOT
		noeudm->op_=newop;
		int * temp = new int[noeudm->nb_var_+1];
		for(int i =0; i<noeudm->nb_var_;i++){
			temp[i]=noeudm -> var_[0];
			delete[] noeudm->var_;
		}
		temp[noeudm->nb_var_]= rand() % nbrvar_;
		noeudm->var_ = temp;
		noeudm ->nb_var_=noeudm ->nb_var_+1;
	}else{ //Si le noeud devient un NOT
		monrand = rand() % 2;
		noeudm->op_=newop;
		switch(noeudm->nb_aretes_)
		{
		case 0: //Le noeud �tait reli� � deux variables
			{
			int* temp1 = new int[1];
			temp1[0]=noeudm->var_[monrand];
			delete[] noeudm->var_;
			noeudm->var_=temp1;
			noeudm -> nb_var_=1;
			}
			break;
		case 1: //Le noeud �tait reli� � une variable et un noeud
			if (monrand==0){
				delete[] noeudm->var_;
				noeudm ->var_=nullptr;
				noeudm -> nb_var_=0;
			} else {
				delete [] noeudm ->aretes_[0];
				delete[] noeudm->aretes_;
				noeudm -> aretes_=nullptr;
				noeudm -> nb_aretes_=0;
			}
			break;
		default: //Le noeud �tait reli� � deux noeuds
			{
			noeud** temp2 = new noeud*[1];
			temp2[0]=noeudm->aretes_[monrand];
			delete[] noeudm -> aretes_[1-monrand];
			delete[] noeudm->aretes_;
			noeudm->aretes_=temp2;
			noeudm -> nb_aretes_=1;
			}
			break;
		}
	}
	
}

arbre::~arbre(){
	//for(int i=0; i<nbr_noeuds_;i++){
	//	delete[] liste_noeuds_[i];
	//}
	delete noeud1_;
	delete[] liste_noeuds_;
}
