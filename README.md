# CAV-Intersection-With-Model-Checking
This project implements an Autonomous Intersection Management (AIM) for Connected and Autonomous Vehicles (CAVs). It uses a Formal Verification technique called Model Checking, by using the Fiacre Language (http://projects.laas.fr/fiacre/papers.php). Fiacre stands for Format Intermédiaire pour les Architectures de Composants Répartis Embarqués (Intermediate Format for the Architectures of Embedded Distributed Components). It is a formal intermediate model to represent both the behavioral and timing aspects of systems, in particular, embedded and distributed systems, for formal verification and simulation purposes. Additionally, the Matplotlib, a Python library, is used as a visualization tool in order to analyze the behavior of the CAVs with animations.


To run FIACRE scripts (.fcr files), use a Linux system or a Linux distribution for Windows. In the second case do the following steps:

1 - Access the folder containing the file 'script.sh'.
2 - Open Power Shell in admin mode (Alt+F+S+A)
3 - Type BASH at the command line to start ubuntu
4 - Type './script.sh file_name.fcr' without ''

After compilation, several files will be generated. The main files are a .tts folder (with petri net and time logic files), a .ktz file (generates reachability graph), and info.txt (contains all state and transition information). The other files are .txt files for use in Python visualization.
