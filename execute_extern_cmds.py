# pour executer les fichiers externes c++, exemple avec le main

import subprocess
import os
from graphics import encapsulation
from plot_fitness import affichage_fitness

nbGenerations=int(input("Combien de générations voulez-vous calculer au maximum ?"))
seuilFitness=int(input("A partir de quelle fitness les calculs peuvent s'arrêter ?"))
nbFilles=int(input("Combien de filles à chaque génération doivent être générées ?"))
nomFichier=str(input("Comment doit s'appeler le fichier qui stockera la formule du meilleur arbre ?"))
nbGenerations,seuilFitness,nbFilles,str(nomFichier)

def compilation_cpp():
	first=subprocess.call(["make","clean"])
	subprocess.call(["make"])
	tmp=subprocess.call(["./main",str(nbGenerations),str(seuilFitness),str(nbFilles),nomFichier])
	encapsulation()
	affichage_fitness()	
	print (tmp)


compilation_cpp()
