class arbre{

	//méthodes
public : 
	arbre(); //constructeur par défaut
	arbre(arbre arbre_mere); //constructeur à partir d'un arbre
	~arbre(); //destructeur
	void calcul_fitness(); 
	arbre creer_fille();


	//attributs
private : 
	noeud noeud_1; //1er noeud de l'arbre
	int fitness;
	noeud* liste_noeuds []; // une liste de noeuds sans ordre précis

}