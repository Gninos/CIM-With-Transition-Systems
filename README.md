# CAV-Intersection-With-Model-Checking
This project implements an Cooperative Intersection Management (CIM) for Connected and Automatized Vehicles (CAVs).  It aims to assess a more flexible use of intersection areas in urban traffic by CAVs. For this, the idea is to build state space abstractions by using Time Transition System (TTS) to execute the specifications of a CIM. In this way, each state represents a secure configuration of the intersection zone with no car crashes, and each state transitions represent different decision-making options. 

To execute the specifications of the model, we use the model checking toolkit FRAC/TINA/SELT, mainly due to the ability of the TINA toolbox to perform a dynamic verification of properties and to create a reachability graph up to a predetermined limit. First, Initially, the FRAC compiler, using a model written in the Fiacre language (http://projects.laas.fr/fiacre/papers.php), generates several branches with all possible combinations of states and transitions in a TTS. These branches behave like parallel paths to reach the same final state (empty control grid), defined by means of a Linear Temporal Logic (LTL). Then, the TINA Toolbox (http://projects.laas.fr/tina/) uses TTS files to create the state space in a compressed binary format (*.ktz*) for a Kripke Transition System. This *.ktz* file, together with the LTL property previously generated, is the input variable of the State-Space Linear Temporal Logic (SELT) model checker, responsible for verifying whether the final state has been reached. These steps ensure that the design presents safe paths for CAVs that are in the control area of a CIM. 

All this data is treated with the aid of the Python language, which transformsstates into nodes, and transitions into edges, to serve as inputs for the graph analysislibrary called NetworkX (https://networkx.github.io/documentation/stable/index.html). This Python package allows the creation, manipulation, andstudy of structures, dynamics, and functions of complex networks. Using the Dijkstra algorithm, NetworkX filters only the paths with fewer transitions, that is, those configu-rations with less overall time to pass through the intersection. After these steps, thereis a guarantee of deadlock-free, safe crossing, and efficiency in terms of travel time.

The process steps are shown below.

![Processo Execução](https://user-images.githubusercontent.com/50747436/82965951-070b8280-9fa0-11ea-8ff6-9d80bba72291.png)

## What do I need to run the scripts?

You will need a Linux distribution to run the scripts. If you don't use Linux, you can install a version on your Windows through the Windows Store. Following the steps below:

- Click Start > Search for "Windows Update".
- Click on "For developers" and activate "Developer Mode". Click Yes to accept the change;
- Open the power shell in administrator mode and type: *Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux*
- Restart the computer
- Access the Windows Store and install one of the Ubuntu Versions
- Wait for the installation. After the installation is complete, follow the prompt to enter the username and password. After that, you are ready to run your linux commands.
- Try first *sudo apt-get update && apt-get upgrade*

Now, you have to install FRAC/TINA/SELT. Follow the steps:

- Download

## How to run the scripts?

To compile the Fiacre scripts (.fcr files), do the following steps:

- Access the folder containing the file 'script.sh'; 
- Open a Power Shell in admin mode (shortcut: Alt+F+S+A);
- Type BASH at the command line to start ubuntu; 
- Type './script.sh file_name.fcr' without ''

After compilation, several files will be generated. The main files are a .tts folder (with petri net and time logic files), a .ktz file (this one generates the reachability graph data), and info.txt (it contains all the state and transition information you will need). The other files are .txt files that will be used to generate views in Python.

## The model

Basically, all Fiacre models have an 8x8 array grid as you can see below:

![grid](https://user-images.githubusercontent.com/50747436/66518370-72f5b500-eabb-11e9-9360-ee2aeeb87d89.png)

0's represent the street cells, 1's are the sidewalk, and the other numbers will be our CAVs. We have a cross intersection, so the CAVs can start from four different roads (A, B, C and D). Each road has four lanes. In the matplotlib each CAVs is represented by colored squares.

The transitions will follow some constraints to play realistic movements. For instance, in a scenario where the yellow CAV below want to cross the intersection (with no road convergence) and it is driving in a straight line, it can't turn over perpendicularly or go back to the same slot that it was. Also, it is not allowed to go ahead, because there is another CAV in front of it.  So, in this situation, the yellow CAV can only turn diagonally.

![mov1](https://user-images.githubusercontent.com/50747436/66520083-e220d880-eabe-11e9-957f-1353b0c2255a.png)

In the same way, if the yellow CAV is making a diagonal movement, it has the following options to choose from.

![mov2](https://user-images.githubusercontent.com/50747436/66580991-b0a71c00-eb55-11e9-971d-d9db89fa0492.png)

These constraints ensure that there will be no abrupt movements.

A round ends when all cars have had a chance to move. So, the model has a starvation-free property that makes all the CAVs to have the opportunity to move in the round. Moreover, it allows the possibility of a CAV to choose to pause and pass its turn.

