class arbre{

	//méthodes
public : 
	arbre(); //constructeur par défaut
	arbre(arbre arbre_mere); //constructeur à partir d'un arbre
	arbre(bool* d);
	~arbre(); //destructeur
	void calcul_fitness(); 
	arbre creer_fille();


	//attributs
private : 
	noeud noeud1_; //1er noeud de l'arbre
	const bool* data_;
	int fitness_;
	noeud* liste_noeuds_ []; // une liste de noeuds sans ordre précis
	int longueur_liste_;
	void mutation_ajout();
	void mutation_deletion();
	void mutation_substitution();
	void mutation_random();
	void compter_noeuds();
	void parcourir_noeud(noeud n);
	void cree_arbre_random();



}