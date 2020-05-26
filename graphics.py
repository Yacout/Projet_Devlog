#A faire :
#installer pip. Si sur MSYS : pacman -S python3-pip puis pip3 install --upgrade pip
#installer graphviz : pip3 install graphviz

from graphviz import Digraph
import matplotlib.pyplot as plt

def plot_adjacency_list(edges_list,file_name):
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
