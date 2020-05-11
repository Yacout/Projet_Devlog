class noeud{

	//méthodes
public : 
	noeud(); //constructeur par défaut
	noeud(noeud* noeud1, noeud* noeud2); //constructeur utilisé en cas de AND ou OR
	noeud(noeud* noeud1); //constructeur utilisé en cas de modification de NOT
	~noeud(); //destructeur

	//attributs
private : 

}