#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


/**
 * Fonction qui sert a supprimer le premier element d'un vecteur
 * Pour pouvoir enlever le nom de la ligne
 * 
 */
template<typename T>
void pop_front(vector<T> &v)
{
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
    while (getline(in,line))
    {
        //Nettoyage du buffer (ligne)
        ligne.clear();

        //On cree un stream de la ligne pour pouvoir lire la ligne
        stringstream ss(line);

        //On lit la ligne
        while (getline(ss,field,',')) 
        {
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

void Affichage(vector<vector<string>> tab){
	//Affichage du tableau
    for (size_t i=0; i<tab.size(); ++i)
    {
        for (size_t j=0; j<tab[i].size(); ++j)
        {
            cout << tab[i][j] << "|"; 
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<string>> tab;
    tab =CreerTableau();
    Affichage(tab);

    
    return 0;
}