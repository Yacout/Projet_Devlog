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
	op_ = op_par;	
	var_ = new int[2];
    var_[0] = var1;
	var_[1] = var2;
	nb_aretes_ = 0;
	nb_var_ = 2;
	nb_const_ = 0;
}

//============================================================================
//Constructeur avec deux noeuds
//============================================================================

noeud::noeud(int op_par, noeud* noeud1, noeud* noeud2){
	op_ = op_par;	
	aretes_ = new noeud*[2];
	aretes_[0] = noeud1;
	aretes_[1] = noeud2;
	nb_aretes_ = 2;
	nb_var_ = 0;
	nb_const_ = 0;
}

//============================================================================
//Constructeur avec une variable et un noeud
//============================================================================

noeud::noeud(int op_par, int var1, noeud* noeud1){
	op_ = op_par;	
	aretes_ = new noeud*[1];
	var_ = new int[1];
	aretes_[0] = noeud1;
	var_[0] = var1;
	nb_aretes_ = 1;
	nb_var_ = 1;
	nb_const_ = 0;
}

//============================================================================
//Constructeur avec deux constantes
//============================================================================

noeud::noeud(int op_par, bool const1, bool const2){
	op_ = op_par;	
	consts_ = new bool[2];
	consts_[0] = const1;
	consts_[1] = const2;
	nb_aretes_ = 0;
	nb_var_ = 0;
	nb_const_ = 2;
}

//============================================================================
//Constructeur avec une constante et un noeud
//============================================================================

noeud::noeud(int op_par, bool const1, noeud* noeud1){
	op_ = op_par;	
	aretes_ = new noeud*[1];
	consts_ = new bool[1];
	aretes_[0] = noeud1;
	consts_[0] = const1;
	nb_aretes_ = 1;
	nb_var_ = 0;
	nb_const_ = 1;
}

//============================================================================
//Constructeur avec une constante et une variable
//============================================================================

noeud::noeud(int op_par, bool const1, int var1){
	op_ = op_par;	
	var_ = new int[1];
	consts_ = new bool[1];
	var_[0] = var1;
	consts_[0] = const1;
	nb_aretes_ = 0;
	nb_var_ = 1;
	nb_const_ = 1;
}

//============================================================================
//Constructeur pour not avec une variable
//============================================================================

noeud::noeud(int op_par, int var1){
	op_ = op_par;	
	var_ = new int[1];
	var_[0] = var1;
	nb_aretes_ = 0;
	nb_var_ = 1;
	nb_const_ = 0;
}

//============================================================================
//Constructeur pour not avec un noeud
//============================================================================

noeud::noeud(int op_par, noeud* noeud1){
	op_ = op_par;	
	aretes_ = new noeud*[1];
	aretes_[0] = noeud1;
	nb_aretes_ = 1;
	nb_var_ = 0;
	nb_const_ = 0;
}

//============================================================================
//
//Destructeur
//
//============================================================================

noeud::~noeud(){
	delete[] aretes_;
	delete[] var_;
	delete[] consts_;
}

//============================================================================
//
//Getters
//
//============================================================================

int noeud::op(){
	return op_;
}

int noeud::nb_aretes(){
	return nb_aretes_;
}

int noeud::nb_var(){
	return nb_var_;
}

int noeud::nb_const(){
	return nb_const_;
}

int* noeud::var(){
	return var_;
}

bool* noeud::consts(){
	return consts_;
}

noeud** noeud::aretes(){
	return aretes_;
}
