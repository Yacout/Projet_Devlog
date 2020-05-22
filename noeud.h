#include <vector>
using namespace std;
class noeud
{

	private: 

		int op_ = 0; //1 pour AND, 2 pour OR, 3 pour NOT
		int nb_aretes_ = 0;
		int nb_var_ = 0;
		int nb_const_ = 0;
		int* var_ = nullptr; //tableau
		bool* consts_ = nullptr; //tableau
		noeud** aretes_ = nullptr; //tableau

	public: 

		//====================================================================
		//Constructeurs
		//====================================================================
		
		//Pour les constructeurs, l'operation doit être précisée sous forme d' 
		//entier (il s'agit de int op_par):
		//1 pour AND
		//2 pour OR
		//3 pour NOT
		
		//ctor par defaut
		
		noeud(); 

		//Constructeurs pour AND and OR
		
		//ctor avec deux variables
		noeud(int op_par, int var1, int var2); 
		//ctor avec deux noeuds
		noeud(int op_par, noeud* noeud1, noeud* noeud2);
		//ctor avec un noeud et une variable
		noeud(int op_par, int var1, noeud* noeud1);
		//ctor avec deux constantes
		noeud(int op_par, bool const1, bool const2);
		//ctor avec une constante et un noeud
		noeud(int op_par, bool const1, noeud* noeud1);
		//ctor avec une constante et une variable
		noeud(int op_par, bool const1, int var1);

		//Constructeurs pour NOT
		
		//ctor pour not avec une variable
		noeud(int op_par, int var1);
		//ctor pour not avec un noeud
		noeud(int op_par, noeud* noeud1);

		//====================================================================
		//Destructeur
		//====================================================================
		
		~noeud(); 

		//====================================================================
		//Getters
		//====================================================================

		int op() const;
		int nb_aretes() const;
		int nb_var() const;
		int nb_const() const;
		int* var() const;
		bool* consts() const;
		noeud** aretes() const;

		//====================================================================
		//Mutateurs
		//====================================================================

		//Mutateur d'opération
		void op(int op_par);

		//====================================================================
		//Compute
		//====================================================================

		//Calcule la valeur du noeud à partir d'une liste de valeurs
		bool compute(const vector<bool> list);

		//====================================================================
		//Size
		//====================================================================

		//donne le nombre de noeuds dans le tableau
		void size(int &ret);

		//====================================================================
		//Liste
		//====================================================================

		//Renvoie une liste de pointeurs vers les noeuds
		void liste(noeud** array,noeud* defaut); //attend en paramètre une liste 
											  //de la bonne taille

};
