import sympy as sp
sp.init_printing() #pour que les expressions soient print de façon jolie

#exemple avec des chiffres
x=sp.symbols('x') #définir x sinon il connait pas
print(sp.simplify(1*x*2+1)) # simplifier l'expression pour qu'elle soit plus lisible et simple
a=12*x**3
f=sp.lambdify(x,a)#traduit une expression Sympy en Python
print(f(3)) #retourne la valeur de cette fonction

#exemple avec des booléens 
x1, x2, x3 =sp.symbols('x1, x2, x3')
f1= (x1 & x2 & x3) | (~x1 & ~x3)
print(sp.simplify(f1))