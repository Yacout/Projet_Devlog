# A faire :
# installer pip. Si sur MSYS : pacman -S python3-pip puis pip3 install --upgrade pip
# installer graphviz : pip3 install graphviz

from graphviz import Digraph
import matplotlib.pyplot as plt


def plot_adjacency_list(edges_list, file_name):
    """
    Plot a network from  a list of edges

    Args:
        edges_list (list): list of edges, each edge is a tuple with two elements
            each element represents a node and each node is represented itself
            by a tuple, containing its id (str), its label (str) and its color (str)
            check the list of colors at https://www.graphviz.org/doc/info/colors.html
        file_name (str): name of the output file

    Example:
        >>> node1 = ("1", '+', 'deepskyblue4')
        >>> node2 = ("2", 'x1', 'firebrick1')
        >>> node3 = ("3", 'x2', 'firebrick1')
        >>> edges = [(node1, node2), (node1, node3)]
        >>> plot_adjacency_list(edges,"test")
    """
    # get nodes
    nodes = []
    for edge in edges:
        nodes.append(edge[0])
        nodes.append(edge[1])
    nodes = list(set(nodes))
    # Build a graph
    g = Digraph('G', filename=file_name)
    # add nodes to graph
    for node in nodes:
        g.node(node[0], label=node[1], color=node[2], style='filled')
    # add edges
    for edge in edges_list:
        g.edge(edge[0][0], edge[1][0])
    # to pdf
    g.render()


def import_txt():
    mon_fichier = open("stockage_txt_formule.txt", "r")
    contenu = mon_fichier.read()
    print(contenu)
    mon_fichier.close()
    return contenu


def import_txt_aretes():
    mon_fichier = open("stockage_txt_aretes.txt", "r")
    contenu = mon_fichier.read()
    print(contenu)
    mon_fichier.close()
    return contenu

 # création d'une tuple par noeud


def cree_tuples_noeuds(contenu):
    liste_noeuds = []

    for line in contenu:
        for i, caractere in enumerate(line):
            if(i < len(contenu)-3):
                if (caractere == 'x'):
                    liste_noeuds.append(
                        len(liste_noeuds), 'x'+str(caractere[i+1])+str(caractere[i+2]), 'firebrick1')
            else:
                if(caractere == '&'):
                    liste_noeuds.append(
                        (len(liste_noeuds), '&', 'deepskyblue4'))
                elif(caractere == '~'):
                    liste_noeuds.append(
                        (len(liste_noeuds), '~', 'deepskyblue4'))
                elif(caractere == '|'):
                    liste_noeuds.append(
                        (len(liste_noeuds), '|', 'deepskyblue4'))

    return liste_noeuds


contenu = import_txt()
contenu_aretes = import_txt_aretes()
liste_noeuds = cree_tuples_noeuds(contenu)
print(liste_noeuds)
