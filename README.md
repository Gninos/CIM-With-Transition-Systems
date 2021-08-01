# Cooperative-Intersection-Management-With-Model-Checking

## Introduction

This project implements an Cooperative Intersection Management (CIM) for Connected and Automatized Vehicles (CAVs).  It aims to assess a more flexible use of intersection areas in urban traffic by CAVs. For this, the idea is to build state space abstractions by using Time Transition System (TTS) to execute the specifications of a CIM. In this way, each state represents a secure configuration of the intersection zone with no car crashes, and each state transitions represent different decision-making options. 

To execute the specifications of the model, we use the model checking toolkit FRAC/TINA/SELT, mainly due to the ability of the TINA toolbox to perform a dynamic verification of properties and to create a reachability graph up to a predetermined limit. First, Initially, the FRAC compiler, using a model written in the Fiacre language (http://projects.laas.fr/fiacre/papers.php), generates several branches with all possible combinations of states and transitions in a TTS. These branches behave like parallel paths to reach the same final state (empty control grid), defined by means of a Linear Temporal Logic (LTL). Then, the TINA Toolbox (http://projects.laas.fr/tina/) uses TTS files to create the state space in a compressed binary format (*.ktz*) for a Kripke Transition System. This *.ktz* file, together with the LTL property previously generated, is the input variable of the State-Space Linear Temporal Logic (SELT) model checker, responsible for verifying whether the final state has been reached. These steps ensure that the design presents safe paths for CAVs that are in the control area of a CIM. 

All this data is treated with the aid of the Python language, which transformsstates into nodes, and transitions into edges, to serve as inputs for the graph analysislibrary called NetworkX (https://networkx.github.io/documentation/stable/index.html). This Python package allows the creation, manipulation, andstudy of structures, dynamics, and functions of complex networks. Using the Dijkstra algorithm, NetworkX filters only the paths with fewer transitions, that is, those configu-rations with less overall time to pass through the intersection. After these steps, thereis a guarantee of deadlock-free, safe crossing, and efficiency in terms of travel time.

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

## How to run the scripts?

To compile the Fiacre scripts (.fcr files), do the following steps:

- Access the folder containing the file 'script.sh'; 

- Type './script.sh file_name.fcr' without ''

After compilation, several files will be generated. The main files are a .tts folder (with petri net and time logic files), a .ktz file (this one generates the reachability graph data), and info.txt (it contains all the state and transition information you will need). The other files are .txt files that will be used to generate views in Python.

## The model

Basically, all Fiacre models have an 8x8 array grid as you can see below:



