#include "./noeud.h"

//============================================================================
//
//Constructeurs
//
//============================================================================


//============================================================================
//Constructeur par défaut
//============================================================================


//============================================================================
//Constructeur avec deux variables
//============================================================================

noeud::noeud(int op_par, int var1, int var2){
	op = op_par;	
	var = new int[2];
    var[0] = var1;
	var[1] = var2;
	nb_aretes = 0;
	nb_var = 2;
	nb_const = 0;
}

//============================================================================
//Constructeur avec deux noeuds
//============================================================================

noeud::noeud(int op_par, noeud* noeud1, noeud* noeud2){
	op = op_par;	
	aretes = new noeud*[2];
	aretes[0] = noeud1;
	aretes[1] = noeud2;
	nb_aretes = 2;
	nb_var = 0;
	nb_const = 0;
}

//============================================================================
//Constructeur avec une variable et un noeud
//============================================================================

noeud::noeud(int op_par, int var1, noeud* noeud1){
	op = op_par;	
	aretes = new noeud*[1];
	var = new int[1];
	aretes[0] = noeud1;
	var[0] = var1;
	nb_aretes = 1;
	nb_var = 1;
	nb_const = 0;
}

//============================================================================
//Constructeur avec deux constantes
//============================================================================

noeud::noeud(int op_par, bool const1, bool const2){
	op = op_par;	
	consts = new bool[2];
	consts[0] = const1;
	consts[1] = const2;
	nb_aretes = 0;
	nb_var = 0;
	nb_const = 2;
}

//============================================================================
//Constructeur avec une constante et un noeud
//============================================================================

noeud::noeud(int op_par, bool const1, noeud* noeud1){
	op = op_par;	
	aretes = new noeud*[1];
	consts = new bool[1];
	aretes[0] = noeud1;
	consts[0] = const1;
	nb_aretes = 1;
	nb_var = 0;
	nb_const = 1;
}

//============================================================================
//Constructeur avec une constante et une variable
//============================================================================

noeud::noeud(int op_par, bool const1, int var1){
	op = op_par;	
	var = new int[1];
	consts = new bool[1];
	var[0] = var1;
	consts[0] = const1;
	nb_aretes = 0;
	nb_var = 1;
	nb_const = 1;
}

