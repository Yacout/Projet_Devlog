# pour executer les fichiers externes c++, exemple avec le main

import subprocess
import os

def compilation_cpp():

	subprocess.call(["g++", "main.cpp"])
	tmp=subprocess.call("./main")
	print (tmp)


compilation_cpp()
