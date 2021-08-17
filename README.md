# Cooperative-Intersection-Management-With-Transition-Systems

## Introduction

This project implements an Cooperative Intersection Management (CIM) for Automatized Vehicles (AVs).  It aims to assess a more flexible use of intersection areas in urban traffic by AVs. For this, the idea is to build state space abstractions by using Time Transition System (TTS) to execute the specifications of a CIM. In this way, each state represents a secure configuration of the intersection zone with no car crashes, and each state transitions represent different decision-making options. 

To execute the specifications of the model, we use the model checking toolkit FRAC/TINA/SELT, mainly due to the ability of the TINA toolbox to perform a dynamic verification of properties and to create a reachability graph up to a predetermined limit. First, Initially, the FRAC compiler, using a model written in the Fiacre language (http://projects.laas.fr/fiacre/papers.php), generates several branches with all possible combinations of states and transitions in a TTS. These branches behave like parallel paths to reach the same final state (empty control grid), defined by means of a Linear Temporal Logic (LTL). Then, the TINA Toolbox (http://projects.laas.fr/tina/) uses TTS files to create the state space in a compressed binary format (*.ktz*) for a Kripke Transition System. This *.ktz* file, together with the LTL property previously generated, is the input variable of the State-Space Linear Temporal Logic (SELT) model checker, responsible for verifying whether the final state has been reached. These steps ensure that the design presents safe paths for CAVs that are in the control area of a CIM. 

All this data is treated with the aid of the Python language, which transforms states into nodes, and transitions into edges, to serve as inputs for the graph analysis library called NetworkX (https://networkx.github.io/documentation/stable/index.html). This Python package allows the creation, manipulation, andstudy of structures, dynamics, and functions of complex networks. Using the Dijkstra algorithm, NetworkX filters only the paths with fewer transitions, that is, those configu-rations with less overall time to pass through the intersection. After these steps, thereis a guarantee of deadlock-free, safe crossing, and efficiency in terms of travel time.

The process steps are shown below.

![Processo Execução](https://user-images.githubusercontent.com/50747436/82965951-070b8280-9fa0-11ea-8ff6-9d80bba72291.png)

## What do I need to run the scripts?

You will need a Linux distribution to run the scripts. If you don't use Linux, you can install a version on your Windows through the Windows Store. Following the steps below:

- Click Start > Search for "Windows Update".
- Click on "For developers" and activate "Developer Mode". Click Yes to accept the change;
- Open the power shell in administrator mode and type: **_Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux_**
- Restart the computer
- Access the Windows Store and install one of the Ubuntu Versions
- Wait for the installation. After the installation is complete, follow the prompt to enter the username and password. After that, you are ready to run your linux commands.
- Updates the list of packages and programs that can be installed on the machine by typing: **sudo apt-get update && apt-get upgrade**

Now, you have to install FRAC/TINA/SELT. Follow the steps:

- Download the 32- or 64-bit version of the file frac.x.y.z.linux.tar.gz from this site http://projects.laas.fr/fiacre/download.php. Also download the file tina.x.y.z.linux.tar.gz from http://projects.laas.fr/tina/download.php. Note: *x.y.z* is the current version of the files
- Move the two files to a folder of your choice
- Inside the folder, open a Power Shell in admin mode (shortcut: Alt+F+S+A)
![t1](https://user-images.githubusercontent.com/50747436/83030018-bcbeeb80-a009-11ea-9456-3ee59b1abe42.png)
- Type **BASH** at the command line to start ubuntu 
- Unzip using the *tar* command: **tar -xf archive.tar.gz**
- Enter the frac-.x.y.z folder and open the Makefile file in a text editor. Replace the FRACLIB variable with: **/mnt/c/...frac-x.y.z/lib**

![t2](https://user-images.githubusercontent.com/50747436/83033249-415f3900-a00d-11ea-91fd-22c155012a09.png)

- Now, go to your home directory (/home/user), by typing: cd ~
- Type: **sudo nano ~/.bash_profile**
- Add the frac and Tina directory to your PATH environment variable by adding the following lines to the end of the file: **export PATH="$PATH:/mnt/c/.../frac-x.y.z"** and **export PATH="$PATH:/mnt/c/.../tina-x.y.z/bin"**
- Press **ctrl+X** and **Y** to save the modifications. 
- To activate the changes in the current shell, you have to "source" the updated bash_profile file. You do this with the command: **source ~/.bash_profile**
- To check if the directories are in PATH, type: echo $PATH
- Type **frac -h** and **tina -h** to test if both are working.
- Now, you need to intall The GNU Compiler Collection (GCC). GCC is a collection of compilers and libraries for C and C++. First type **sudo apt install build-essential**, and, then **sudo apt-get install manpages-dev**
- To validate that the GCC compiler is successfully installed, use the **gcc --version** command which prints the GCC version

## How to run the Fiacre scripts?

To compile the Fiacre scripts (*.fcr* files), do the following steps:

- Access the folder containing the file 'script.sh' (Explanation below. More details in: http://projects.laas.fr/fiacre/doc/usage.html); 

![scriptbash](https://user-images.githubusercontent.com/50747436/127790261-963191c2-71aa-4c62-9b41-3bebb14a25e5.png)

- Type './script.sh file_name.fcr' without ''

After compilation, several files will be generated. The main files are a *.tts* folder (with petri net and time logic files), a *.ktz* file (this one generates the reachability graph data), *info.txt* (it contains all the state and transition information you will need) and *reach_graph.txt* (reachability graph data as a *.txt* file). The other *.txt* files that will be used to generate views in Python.

## The model

Basically, all Fiacre models have an 8x8 array grid. All tests are performed on cross-shaped crosses, where only 48 square and discrete cells are considered in the modeling. It is assumed that the cells have areas capable of supporting the measurements of a regular car. Two scenarios are used:

- Scenario 1 - intersection of four vehicle streams coming from north, south, east and west.

- Scenario 2 - intersection of a main one-way avenue going west-east and a secondary avenue with two-way road going north-south, which can be routed to the main road. 

![grids](https://user-images.githubusercontent.com/50747436/127790759-73dc4b70-d29c-4ab5-acfd-8fd22ed14699.PNG)

To test the use of space in Scenarios 1 and 2, it was decided to make a comparison between two different reserve models: Flexible (reservations have few lane change restrictions, as shown in the right figure below) and Conventional (strict movements to traditional paths , in accordance with traffic laws, and without the possibility of changing between lanes, as shown in the left figure below). More details about how the model works are described in the scripts comments.

![image](https://user-images.githubusercontent.com/50747436/127791241-fd968220-9066-4882-94f4-cb94984d9f02.png)

## Data analysis with Python

The *graphs_networkX - All Paths.py* file uses *info.txt*, *reach_graph.txt* and *init.txt* files as input arguments to parse shortest paths to the desired final state. Dijkstra's method is present in NetworkX routines, in the *shortest_path*(G, source, target, method='dijkstra') and *all_shortest_path*(G, source, target, method='dijkstra') functions, where *G* stores the nodes and the graph arcs, *source* indicates the node with the initial condition, and *target* is the node to be reached. 

While *shortest_path* returns a single list of nodes that belong to one of the shortest paths from source to destination, *all_shortest_path* builds a Python *generator*, which doesn't return a single value, instead generating an iterator object with a sequence of values, corresponding to all paths between the source and the destination. More details are described in the scripts comments. 

## Other Examples

Scripts and results of other initial conditions are in this google drive shared folder https://drive.google.com/drive/folders/1_O31kkDf2P9kuwZVI_W8d8l33KbWjybA?usp=sharing
