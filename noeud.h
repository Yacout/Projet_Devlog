/// \class noeud
///
/// La classe noeud consiste en un unique noeud de l'arbre
///
/// La classe noeud peut soit être reliée à d'autres noeuds,
/// soit contenir des variables ou des constantes. 
/// En raison de cette structure, toute la structure de l'arbre est accessible
/// depuis le premier noeud de ce dernier.

#include <vector>
class arbre;
using namespace std;

class noeud
{

	friend class arbre;

	private: 

		int op_ = 0; /*!< Opération réalisée par le noeud:
					   * 1 pour AND
					   * 2 pour OR
					   * 3 pour NOT */
		int nb_aretes_ = 0; /*!< Nombre d'autre noeuds auquel le noeud est relié
							  */
		int nb_var_ = 0; /*!< Nombre de variables que contient le noeud */
		int nb_const_ = 0; /*!< Nombre de constantes que contient le noeud */
		int* var_ = nullptr; /*!< tableau des variables contenus par le noeud */
		bool* consts_ = nullptr; /*!< tableau des constantes contenues par le 
								   * noeud */
		noeud** aretes_ = nullptr; /*!< tableau de pointeurs vers les noeuds
									 * auxquels le noeud est relié */

	public: 

		//====================================================================
		//Constructeurs
		//====================================================================

		
		///
		/// Constructeur par défaut: inutilisé
		///
		
		noeud(); 

		//ctor pour AND et OR 

		//ctor avec deux variables
		
		/// Constructeurs de la classe noeud avec deux variables,
		/// pour les opération AND et OR
		///
		/// \param op_par l'opération réalisée par le noeud:
		/// 1 pour AND, 2 pour OR
		/// \param var1 un entier indiquant la position de la variable dans
		/// une liste de booléens
		/// \param var2 id.
		
		noeud(int op_par, int var1, int var2);

		//ctor avec deux noeuds

		/**
		 * Constructeur de la classe noeud avec deux noeuds,
		 * pour les opération AND et OR
		 *
		 * @param op_par l'opération réalisée par le noeud:
		 * 1 pour AND, 2 pour OR
		 * @param noeud1 un pointeur vers un noeud
		 * @param noeud2 id.
		 */

		noeud(int op_par, noeud* noeud1, noeud* noeud2);

		//ctor avec une variable et un noeud

		/**
		 * Constructeur de la classe noeud avec une variable et un noeud,
		 * pour les opération AND et OR
		 *
		 * @param op_par l'opération réalisée par le noeud:
		 * 1 pour AND, 2 pour OR
		 * @param var1 un entier indiquant la position de la variable dans
		 * une liste de booléens
		 * @param noeud1 un pointeur vers un noeud
		 */

		noeud(int op_par, int var1, noeud* noeud1);

		//ctor avec deux constantes

		/**
		 * Constructeur de la classe noeud avec deux constantes,
		 * pour les opération AND et OR
		 *
		 * @param op_par l'opération réalisée par le noeud:
		 * 1 pour AND, 2 pour OR
		 * @param const1 une constante booléenne
		 * @param const2 id.
		 */

		noeud(int op_par, bool const1, bool const2);

		//ctor avec une constante et un noeud

		/**
		 * Constructeur de la classe noeud avec une constante et un noeud
		 * pour les opération AND et OR
		 *
		 * @param op_par l'opération réalisée par le noeud:
		 * 1 pour AND, 2 pour OR
		 * @param const1 une constante booléenne
		 * @param noeud1 un pointeur vers un noeud
		 */

		noeud(int op_par, bool const1, noeud* noeud1);

		//ctor avec une constante et une variable

		/**
		 * Constructeur de la classe noeud avec une constante et une variable,
		 * pour les opération AND et OR
		 *
		 * @param op_par l'opération réalisée par le noeud:
		 * 1 pour AND, 2 pour OR
		 * @param const1 une constante booléenne
		 * @param var1 un entier indiquant la position de la variable dans une
		 * liste de booléens
		 */

		noeud(int op_par, bool const1, int var1);

		//Constructeurs pour NOT
		
		//ctor pour not avec une variable
		
		/**
		 * Constructeur de la classe noeud avec une variable
		 * pour l'opération NOT
		 *
		 * @param var1 un entier indiquant la position de la variable dans une
		 * liste de booléens
		 */

		noeud(int var1);

		//ctor pour not avec un noeud

		/**
		 * Constructeur de la classe noeud avec un noeud
		 * pour l'opération NOT
		 *
		 * @param noeud1 un pointeur vers un noeud
		 */

		noeud(noeud* noeud1);
		
		//Constructeur de copie

		/**
		 * Constructeur de copie, réalise une copie profonde
		 *
		 * @param acopier un noeud passé par référence constante
		 */
		
		noeud(const noeud&);

		//====================================================================
		//Destructeur
		//====================================================================
		
		/**
		 * Destructeur de la classe noeud
		 *
		 *
		 * Ce destructeur est récursif: il détruit le noeud sur lequel il est
		 * appelé, ainsi que tous les noeuds en dessous de celui-ci
		 */
		
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
		void liste(noeud** array,int i = 0); //attend en paramètre une liste 
											  //de la bonne taille

};
