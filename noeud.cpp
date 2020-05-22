#include "./noeud.h"
#include <iostream>

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

noeud::noeud(int var1){
	op_ = 3;	
	var_ = new int[1];
	var_[0] = var1;
	nb_aretes_ = 0;
	nb_var_ = 1;
	nb_const_ = 0;
}

//============================================================================
//Constructeur pour not avec un noeud
//============================================================================

noeud::noeud(noeud* noeud1){
	op_ = 3;	
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
	delete[] var_;
	delete[] consts_;
	delete[] aretes_;
}

//============================================================================
//
//Getters
//
//============================================================================

int noeud::op() const{
	return op_;
}

int noeud::nb_aretes() const{
	return nb_aretes_;
}

int noeud::nb_var() const{
	return nb_var_;
}

int noeud::nb_const() const{
	return nb_const_;
}

int* noeud::var() const{
	return var_;
}

bool* noeud::consts() const{
	return consts_;
}

noeud** noeud::aretes() const{
	return aretes_;
}

//============================================================================
//
//Mutateurs
//
//============================================================================

//============================================================================
//Mutateur d'opération
//============================================================================

void noeud::op(int op_par){
	op_ = op_par;
}

//============================================================================
//
//Compute
//
//============================================================================

bool noeud::compute(const vector<bool> list){

	//========================================================================
	//Cas pour AND and OR 
	//========================================================================
	
	//Deux noeuds
	if (nb_aretes_ == 2){ 
		switch (op_){
			case 1: return aretes_[0]->compute(list) 
					&& aretes_[1]->compute(list);
			case 2: return aretes_[0]->compute(list) 
					|| aretes_[1]->compute(list);
		}
	} 
	//Un noeud et une variable
	else if (nb_aretes_ == 1 && nb_var_ == 1){
		switch (op_){
			case 1: return aretes_[0]->compute(list)
					&& list[var_[0]];
			case 2: return aretes_[0]->compute(list)
					|| list[var_[0]];
		}
	} 
	//Un noeud et une constante
	else if (nb_aretes_ == 1 && nb_const_ == 1){
		switch (op_){
			case 1: return aretes_[0]->compute(list)
					&& consts_[0];
			case 2: return aretes_[0]->compute(list)
					|| consts_[0];
		}
	} 
    //Deux variables
	else if (nb_var_ == 2){
		switch (op_){
			case 1: return list[var_[0]]
					&& list[var_[1]];
			case 2: return list[var_[0]]
					|| list[var_[1]];
		}
	} 
	//Une variable et une constante
	else if (nb_var_ == 1 && nb_const_ == 1){
		switch (op_){
			case 1: return list[var_[0]]
					&& consts_[0];
			case 2: return list[var_[0]]
					|| consts_[0];
		}
	} 
	//Deux constantes
	else if (nb_const_ == 2){
		switch (op_){
			case 1: return consts_[0]
					&& consts_[1];
			case 2: return consts_[0]
					|| consts_[1];
		}
	}

	//========================================================================
	//Cas pour NOT
	//======================================================================== 
	
	//Un noeud
	else if (op_ == 3 && nb_aretes_ == 1){
		return !aretes_[0]->compute(list);
	}

	//Une variable
	else if (op_ == 3 && nb_var_ == 1){
		return !list[var_[0]];
	}

	return 0; //return par défaut pour éviter les erreurs de compilation,
			  //à modifier
}

//============================================================================
//
//Size
//
//============================================================================

void noeud::size(int &ret){
	ret++;
	if (nb_aretes_ > 0){
		for (int i=0; i<nb_aretes_; i++){
			aretes_[i]->size(ret);
		}
	}
}

//============================================================================
//
//Liste
//
//============================================================================

void noeud::liste(noeud** array, noeud* defaut){
	int u=0;
	while(array[u]!=defaut){
		u++;
	}
	array[u]=this;
	if(nb_aretes_>=1){
		aretes_[0]->liste(array,defaut);
		
		if(nb_aretes_==2){
			aretes_[1]->liste(array,defaut);	
		}
	}
}


 













