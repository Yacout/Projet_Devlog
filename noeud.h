class noeud
{

	private: 

		int op = 0; //1 pour AND, 2 pour OR, 3 pour NOT
		int nb_aretes = 0;
		int* var = nullptr; //tableau
		bool* consts = nullptr; //tableau
		noeud* edges = nullptr; //tableau

	public: 

		//====================================================================
		//Constructeurs
		//====================================================================
		
		//Pour les constructeurs, l'operation doit être précisée sous forme de 
		//cstring (il s'agit de const char* op)
		
		//ctor par defaut
		noeud(); 
		//ctor avec deux variables
		noeud(const char* op, int var1, int var2); 
		//ctor avec deux noeuds
		noeud(const char* op, noeud* noeud1, noeud* noeud2);
		//ctor avec un noeud et une variable
		noeud(const char* op, int var, noeud* noeud);
		//ctor avec deux constantes
		noeud(const char* op, bool const1, bool const2);
		//ctor avec une constante et un noeud
		noeud(const char* op, bool const1, noeud* noeud);
		//ctor avec une constante et une variable
		noeud(const char* op, bool const1, int var1);
		//ctor pour not avec une variable
		noeud(const char* op, int var);
		//ctor pour not avec un noeud
		noeud(const char* op, noeud* noeud);

		//====================================================================
		//Destructeur
		//====================================================================
		
		~noeud(); //destructeur

};
