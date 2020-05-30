#include <string>

#include <sstream>

#include <iostream>

#include <vector>

#include <fstream>

#include "arbre.h"

using namespace std;

/**

 * Fonction qui sert a supprimer le premier element d'un vecteur

 * Pour pouvoir enlever le nom de la ligne

 * 

 */

template<typename T>

void pop_front(vector<T> &v){

    if (v.size() > 0) {

        v.erase(v.begin());

    }

}


vector<vector<string>> CreerTableau(){

    //Upload du fichier

    ifstream in("binary_gene_expression_ACE2_tfs.csv");

    string line, field;

    //On va stocker les donnees dans des vecteurs

    vector<vector<string>> tab;  //un vecteur de vecteurs pour le tableau

    vector<string> ligne;          //un vecteur pour la ligne

    //On lit la ligne du fichier tant qu'il reste des lignes

    while (getline(in,line)){

        //Nettoyage du buffer (ligne)

        ligne.clear();

        //On cree un stream de la ligne pour pouvoir lire la ligne

        stringstream ss(line);

        //On lit la ligne

         while (getline(ss,field,',')) {
            //on ajoute le contenu de la ligne au vecteur

            ligne.push_back(field); 

        }

        //on supprime la colonne de nom du CSV

        pop_front(ligne);
        //On ajoute toute la ligne au tableau 2D

         tab.push_back(ligne); 
    }
    return tab;

}



vector<vector<bool>> ConversionTableau(vector<vector<string>> tab){

    vector<vector<bool>> tab2;

    for (size_t i=0; i<tab.size(); ++i) {

        vector<bool> tab_ligne;

        for (size_t j=0; j<tab[i].size(); ++j){

            if (tab.at(i).at(j)=="0") {

                tab_ligne.push_back(0); // tab.at(i).at(j) = tab[i][j]

            }

            else if (tab.at(i).at(j)=="1") tab_ligne.push_back(1);

        }

        tab2.push_back(tab_ligne);


    }

    return tab2; 

}


void AffichageString(vector<vector<string>> tab){

    //Affichage du tableau de booléens 

    for (size_t i=0; i<tab.size(); ++i) {

        for (size_t j=0; j<tab[i].size(); ++j) {

            cout << tab.at(i).at(j) << "|"; 

        }

        cout << "\n";
    }

}

void Affichage(vector<vector<bool>> tab){

    //Affichage du tableau de booléens 
    for (size_t i=1; i<tab.size(); ++i){

        for (size_t j=0; j<tab[i].size(); ++j){

            cout << tab.at(i).at(j) << "|"; 

        }

        cout << "\n";
    }

}

int main() {
    /*arbre* a1 = new arbre(119);
    arbre* a2 = new arbre(119);

    delete a2;
    cout<<"hi";
    delete a1;*/

    int nb_generationsmax = 100;
    int seuil_fitness = -50;
    int nbr_filles = 20;
    int nbgeneration = 0;

    vector<vector<string>> tab;

    vector<vector<bool>> tab2;

    tab =CreerTableau();

    //AffichageString(tab);

    tab2= ConversionTableau(tab);
    
    arbre** arbres_acomparer = new arbre*[nbr_filles];
    arbre* candidat;
    int indexCandidat=0;
    //cout << tab2.at(0).at(119) << endl;
    //int nombrevar = (tab2[1].size())-1;
    ///arbre* monarbre = new arbre(119);
    
    for(int i=0; i<5;i++){
    	arbres_acomparer[i] = new arbre(119);
    	arbres_acomparer[i]->calcul_fitness(tab2);
    	if (arbres_acomparer[indexCandidat]->fitness_ < arbres_acomparer[i]->fitness_){
    	    indexCandidat=i;
    	}
    }
    for(int i=0;i<5;i++){
        cout << arbres_acomparer[i]->fitness_ <<endl;
        if (i != indexCandidat) {
            delete arbres_acomparer[i];
        }
    }
    cout << indexCandidat << endl;

    candidat = arbres_acomparer[indexCandidat];
    
    while (nb_generationsmax > nbgeneration&& seuil_fitness > candidat->fitness_) {
        indexCandidat = 0;
        for (int i = 0; i < nbr_filles; i++) {
            arbres_acomparer[i] = candidat->creer_fille();
            arbres_acomparer[i]->calcul_fitness(tab2);
            if (arbres_acomparer[indexCandidat]->fitness_ < arbres_acomparer[i]->fitness_) {
                indexCandidat = i;
            }
        }
        delete candidat;
        candidat = arbres_acomparer[indexCandidat];

        for (int i = 0; i < nbr_filles; i++) {
            if (i != indexCandidat) {
                delete arbres_acomparer[i];
            }
        }
        nbgeneration++;
    }
    cout << candidat->fitness_ << endl;
    cout << nbgeneration << endl;
    
    //Affichage(tab2);

    //cout<<tab2.size()<<endl;

    return 0;
}
