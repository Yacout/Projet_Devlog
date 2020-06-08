import matplotlib.pyplot as plt

def import_txt():
	with open("stockage_txt_fitness.txt","r") as mon_fichier :
		liste_fitness=mon_fichier.readlines()

	return liste_fitness
def conversion(liste_fitness):
	for i in range(len(liste_fitness)):
		liste_fitness[i].strip()

	for i in range(0,len(liste_fitness)):
		liste_fitness[i]=int(liste_fitness[i])
	return liste_fitness

liste_fitness= import_txt()
liste_fitness_int=conversion(liste_fitness)


print(liste_fitness_int)
n=len(liste_fitness)
index=[]
for i in range(n):
	index.append(i)

plt.plot(liste_fitness,index)
plt.xlabel('Numéro de la génération')
plt.ylabel('fitness')
plt.show()
