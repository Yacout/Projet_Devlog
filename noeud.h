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
		//ctor pour not avec une variable
		noeud(int op_par, int var1);
		//ctor pour not avec un noeud
		noeud(int op_par, noeud* noeud1);

		//====================================================================
		//Destructeur
		//====================================================================
		
		~noeud(); //destructeur

};
