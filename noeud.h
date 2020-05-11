class noeud
{

	private: 

		int nb_aretes = 0;
		int* var = nullptr;
		noeud* edges = nullptr;
		bool* res = nullptr;

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
		//ctor pour not avec une variable
		noeud(const char* op, int var);
		//ctor pour not avec un noeud
		noeud(const char* op, noeud* noeud);

		//====================================================================
		//Destructeur
		//====================================================================
		
		~noeud(); //destructeur

};
