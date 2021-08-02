"""
Created on Wed Nov  6 22:48:17 2019

@author: Georgios Ninos, Master's candidate at UFSC
"""
############################################################################
# LIBRARIES
import networkx as nx
import re
import ast
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
import xlsxwriter
from collections import Counter
import pandas as pd
import matplotlib.ticker as tick
from matplotlib.ticker import MaxNLocator
import os
plt.rcParams["figure.figsize"] = [20, 20]
############################################################################
# Setting the filepath
dir_path = os.path.dirname(os.path.realpath(__file__))
info_path = dir_path + "\\info.txt"
reach_path = dir_path + "\\reach_graph.txt"
init_path = dir_path + "\\init.txt"

###########################################################################
# Defining patterns 'pat1' and 'pat2' to be found in the file.
markings = []
pat1 = re.compile(",")  
pat2 = re.compile("=0")  
log_info =  []
############################################################################
# Reading the data to extract the states of the system (markings),
# the final state (dead marking) and the number of CAVs

with open (info_path, 'rt') as info:    
    for t in info: 
        
        # If a pattern 'pat2' is found, the item is defined as the target 
        # and its index is added to target variable
        t2 = t
        if pat2.search(t) != None:
            t2 = re.sub(r' : =0,.*', '', t2.rstrip('\n'))
            target = t2
            print("Target found")
                 
        # If a pattern 'pat1 is found, the item is defined as a marking (state)
        if pat1.search(t) != None:
            # the markings are broken into lines 
            # (rstrip command) and added to the markings list.
            t = re.sub(r'.* : =0,', '', t)
            markings.append(eval(t.rstrip('\n')))
            #markings.append(np.array(ast.literal_eval((t.rstrip('\n')))).tolist())
                
print("Target found. Target is the state: " + target)

#############################################################################
# Extracting the initial road info for each car
init_file = open(init_path, 'r')
init_list = [line.strip().split(' ') for line in init_file.readlines()]
init_list = np.array(ast.literal_eval(init_list[0][0])).tolist()

#############################################################################
# Defining the number of vehicles
# n = number of vehicles
n = len(init_list) 

##############################################################################
## Plotting the initial condition  
m0 = markings [0] # stores the initial state

##############################################################################
## Plotting the initial condition  
print("Plotting the initial condition  ... ")

color = ['blue','red','olive', 'green']


plt.figure(figsize=(8,8))
#plt.rcParams['figure.figsize'] = (8,8) 

# Setting grid lines
c   = 0
while c < 7:

    line = plt.Line2D((0.5+c, 0.5+c), (-0.5, 7.5), lw=1.0, ls='--', color='k')
    plt.gca().add_line(line)
    c = c + 1

d = 0
while d < 7:
    line = plt.Line2D((-0.5, 7.5), (0.5+d, 0.5+d), lw=1.0, ls='--', color='k')
    plt.gca().add_line(line)
    d = d + 1

# Setting plot limits                     
plt.xlim(-0.5, 7.5)
plt.ylim(-0.5, 7.5)
# Setting the forbidden cells (sidewalks)
rectangle1 = plt.Rectangle((-0.5, -0.5), 2, 2, fc='gray')
plt.gca().add_patch(rectangle1)
rectangle2 = plt.Rectangle((5.5, -0.5), 2, 2, fc='gray')
plt.gca().add_patch(rectangle2)
rectangle3 = plt.Rectangle((-0.5, 5.5), 2, 2, fc='gray')
plt.gca().add_patch(rectangle3)
rectangle4 = plt.Rectangle((5.5, 5.5), 2, 2, fc='gray')
plt.gca().add_patch(rectangle4)
plt.gca().invert_yaxis()

plt.arrow(2.5, 0.5, 0.0, 1.5, head_width=0.2, head_length=0.4, fc= 'blue', ec= 'blue', width=0.08)
plt.arrow(0.5, 4.5, 1.5, 0.0, head_width=0.2, head_length=0.4, fc= 'red', ec= 'red', width=0.08)
plt.arrow(4.5, 6.5, 0.0, -1.5, head_width=0.2, head_length=0.4, fc= 'olive', ec= 'olive', width=0.08)
plt.arrow(6.5, 2.5, -1.5, 0.0, head_width=0.2, head_length=0.4, fc= 'green', ec= 'red', width=0.08)

# Setting plot legends 
for mm in range (n):         
    ff, = plt.plot(m0[0][mm],m0[1][mm],'s', mfc = color[init_list[mm]-1], ms = 24)    
plt.title('Condição inicial', y = 1.0, fontsize=20)
plt.draw()
plt.savefig('Condição inicial.png')


print("Defining the number of states...")
# Defining the number of states
n_states= len(markings) # stores the total number of states
  

print("Reading the transitions...")
#############################################################################
# Extracting the transitions of the Reachability Graph
reach_file = open(reach_path, 'r')
reach_list = [line.strip().split(' ') for line in reach_file.readlines()]

print("Read completed")

# This FOR loop treats transitions to be read in networkx
c2 = 0 #counter2
for row in reach_list:

       line=str(row); 
       line2 = line.translate({ord(i): None for i in '[()]'})
       line3 = line2.translate({ord(i): None for i in "'"})
       line4 = line3.split(',')
       line4.pop(1)
       reach_list[c2] = line4
       c2+=1

#############################################################################
# Starting the node composition of the reachability graph
print("Starting the composition of the reachability graph")
nodes = ["{:1d}".format(x) for x in range(n_states)] # stores all the states Id    

############################################################################
# Selecting all the states one transition before the final state to count the 
# length of the other paths.
tr_predecessors = [tr for tr in reach_list if target in tr[1]]
st_predecessors = [s[0] for s in reach_list if target in s[1]]

# removing all the transition that end up into the final state, in order to 
# seek for the shortest paths to all the predecessors states
for tpred in tr_predecessors:
    reach_list.remove(tpred)

# Creating a graph
G = nx.Graph()
# Adding the nodes of the graph from "nodes" list. Nodes are the states
G.add_nodes_from(nodes)
# Adding the edges of the graph from "reach_list" list. Edges are the transitions
G.add_edges_from(reach_list) 

print(" ")
print("Number of States: "+ str(G.number_of_nodes()))
print("Number of Transitions: "+ str(G.number_of_edges()+len(tr_predecessors)))
log_info.append("Number of States: " +str(G.number_of_nodes()))
log_info.append("Number of Transitions: "+ str(G.number_of_edges()+len(tr_predecessors)))

##reach_list = [] # clear reach_list to save memory. it will be not used anymore
#
############################################################################
## Setting all the possible paths from source '0' to predecessors target.
## Selecting only the states that represents a complete round
## to save memory space
print("Setting all the possible paths from source '0' to predecessors target... ")
print("Selecting only the nodes that represent a complete round...")
all_paths = []
complete_round_nodes = []
bin_steps = []
bin_rounds = []

for pred in st_predecessors:
    ppaths = [p for p in nx.all_shortest_paths(G, '0', pred)]
    aplist = []
    for ap in ppaths:
       ap.pop(0) # removes markings[0] from each "ap" to help the counting after
       apaux = ['0'] # it will store the nodes that represent a complete round
                     # the initial state is the initial condition      
       ccounter = n # initial counter of remaining cars in the grid
       cleft = 0 # cars that left the grid
       while cleft != n:
           # in the first iteration it will append the marking [ccounter-1]
           # because it represents the firt state that all cars have moved
           # ex: markings[0], markings[1], markings[2], ..., markings[ccounter-1]
           apaux.append(ap[ccounter-1])
           # 'zip'  is an iterator of tuples where each x and items in markings 
           # are paired together. It sums '1' if both iterators are equal to '7'
           # because it is a signal that the car has already left the grid
           cleft = sum([1 for i, j in zip(markings[int(ap[ccounter-1])][0], \
                        markings[int(ap[ccounter-1])][1]) if i == 7 and j == 7])      
           ccounter = ccounter + n - cleft       
       aplist.append({'steps': len(ap), 'rounds': len(apaux)-1, 'path': apaux})
       for aa in apaux:
           if aa not in complete_round_nodes:
               complete_round_nodes.append(aa)
       if len(ap) not in  bin_steps: #selects the bin_steps
           bin_steps.append(len(ap))
       if len(apaux)-1 not in  bin_rounds: #selects the bin_rounds
           bin_rounds.append(len(apaux)-1)
    all_paths.extend(aplist)

print("Total of paths that find the target: "+str(len(all_paths)))
log_info.append("Total of paths that find the target: "+ str(len(all_paths)))

print("Number of states that represent a completed round: "+str(len(complete_round_nodes)))
log_info.append("Number of states that represent a completed round: "+ str(len(complete_round_nodes)))

print("Least number of steps until cars exit the intersection: "+str(bin_steps[0]))
log_info.append("Least number of steps until cars exit the intersection: "+ str(bin_steps[0]))

print("Least number of rounds until cars exit the intersection: "+str(bin_rounds[0]))
log_info.append("Least number of rounds until cars exit the intersection: "+ str(bin_rounds[0]))

#############################################################################
# Saving the outputs in a csv file

df0 = pd.DataFrame(data={"log_info": log_info})
df0.to_csv("./log_info.csv", sep=',',index=False)


## erasing the states that not represent a completed round to save memory space
#mcounter = 0
#for m in markings:
#    if str(mcounter) not in complete_round_nodes:
#        markings[mcounter] = []
#    mcounter += 1
#
#############################################################################
### Selecting the paths for steps and rounds bins to create a distribution 
#
#bin_steps.sort() # put the items in order 
#bin_rounds.sort() # put the items in order 
#
#bin_paths1 = [] # it will store the paths by steps
#bin_paths2 = [] # it will store the paths by rounds and steps
#
#for bs in bin_steps:
#    # it sums 1 for each step bin found in a path
#    sum_paths = sum(1 for ap in all_paths if ap.get('steps') == bs)
#    bin_paths1.append(sum_paths)
#    
### Plotting the paths distribution by steps using pd
#print("Plotting the paths distribution by steps ... ")
#
#df = pd.DataFrame({"Nº de caminhos": bin_paths1}, index=bin_steps)
#ax = df.plot(kind="bar", fontsize = 20)
#for p in ax.patches:
#    ax.annotate("%.f" % p.get_height(), (p.get_x() + p.get_width() / 2., \
#    p.get_height()), fontsize=20, ha='center', va='center', xytext=(0, 20), \
#        textcoords='offset points')  
#plt.yscale('log')
#plt.xticks(rotation=30, horizontalalignment="center")
#plt.title("Distribuição de caminhos por número de passos",fontsize=30)
#plt.xlabel("Número de passos", fontsize=25)
#plt.ylabel("Número de caminhos (escala logarítmica)", fontsize=25)
#plt.legend(fontsize=15,loc='upper left')
#plt.savefig('Gráfico de Barras - Distribuição de caminhos.png', bbox_inches = 'tight')
#
#print("Selecting the paths by rounds ... ")
#
#for br in bin_rounds:
#    slist =  [0 for bs in bin_steps]
#    # it sums 1 in slist for each step bin found in a path
#    # it separates by round and steps
#    for ap in all_paths:
#        if br == ap.get('rounds'):
#            slist[bin_steps.index(ap.get('steps'))] += 1
#    bin_paths2.append(slist)
#
#dicts = {}
#keys = bin_rounds
#for k in keys:
#    # making a dictionary with rounds as keys
#     dicts[k] = [bp for bp in bin_paths2 if bin_paths2.index(bp) == bin_rounds.index(k)]
#     dicts[k] = dicts[k][0]
#
### Saving the paths distribution by rounds using pd
#df2 = pd.DataFrame(dicts, index=bin_steps)
#df2.to_excel("Caminhos por rodadas.xlsx")
#

#
###############################################################################
### Plottting a path instance for each step range of the least number of rounds
#               
#print("choosing the paths for each step range of the least number of rounds... ")
#selection1 = []
#
#for bs in bin_steps:
#    count = 0
#    for ap in all_paths:    
#        if ap.get('rounds') == bin_rounds[0] and ap.get('steps') == bs and count == 0:
#               selection1.append(ap.get('path'))
#               count +=1
#
#ypaths = [] # it will store the y progression of all paths
#xpaths = [] # it will store the x progression of all paths
#
#for sample in selection1:
#   ydata = [[] for _ in range(n)] # it will store the y position of each car in each path
#   xdata = [[] for _ in range(n)] # it will store the y position of each car in each path
#
#   for nn in range(n):
#         fx = []
#         fy = []
#         for icl in sample:
#                 fx.append(markings[int(icl)][0][nn])
#                 fy.append(markings[int(icl)][1][nn])
#         while fx[-1] == 7:
#             fx.pop(-1)
#         while fy[-1] == 7:
#             fy.pop(-1)
#         xdata[nn].append(fx)
#         ydata[nn].append(fy)
#
#   xpaths.append(xdata)
#   ypaths.append(ydata)
#
## Concatenating the x and y position of the selected paths in order to plot
## different figures
#   
#if n == 8:
#    sp1 = 2
#    sp2 = 4
#if n == 10:
#    sp1 = 2
#    sp2 = 5
#if n == 12:
#    sp1 = 3
#    sp2 = 4
#if n == 14:
#    sp1 = 3
#    sp2 = 5
#
#for ss in range(len(selection1)):    
#   # Settting the x,y positions
#   xxdata = []
#   yydata = []
#   
#   for nn in range(n):       
#        
#        xxdata.append(xpaths[ss][nn][0])                 
#        yydata.append(ypaths[ss][nn][0])
#       
#   fig, axes = plt.subplots(sp1,sp2, sharex=True, sharey=True, figsize=(30,15))
#   for i, ax in enumerate(axes.flatten()):
#        # Plotting 
#        ax.plot(xxdata[i],yydata[i],marker= 's', ms = 10)
#        # Adding the final state 
#        ax.plot(xxdata[i][-1],yydata[i][-1],marker= 's', mfc = 'black', ms = 10,label='Posição final')
#        # Adding legends
#        leg = ax.legend(loc='upper left')
#                      
#        # Setting the forbidden cells (sidewalks)
#        # Setting plot limits                     
#        ax.set_xlim([-0.5, 7.5])
#        ax.set_ylim([-0.5, 7.5])
#        # Setting the forbidden cells (sidewalks)
#        rectangle1 = plt.Rectangle((-0.5, -0.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle1)
#        rectangle2 = plt.Rectangle((5.5, -0.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle2)
#        rectangle3 = plt.Rectangle((-0.5, 5.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle3)
#        rectangle4 = plt.Rectangle((5.5, 5.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle4)
#        ax.invert_yaxis()
#        fig.suptitle('Caminho ' + str(ss+1) + ' - Número de rodadas: ' + str(bin_rounds[0]) + \
#                     '. Número de passos: ' + str(bin_steps[ss]), fontsize=30)
#        ax.title.set_text('. Carro: ' +str(i+1))
#        
#        # Setting grid lines
#        for il in range(7):
#            line = Line2D([0.5+il, 0.5+il], [-0.5, 7.5], linestyle = '--', linewidth = 1, \
#                              color = [0,0,0], zorder = 1, transform = ax.transData)
#            line2 = Line2D([-0.5, 7.5], [0.5+il, 0.5+il], linestyle = '--', linewidth = 1, \
#                              color = [0,0,0], zorder = 1, transform = ax.transData)
#            ax.lines.append(line)
#            ax.lines.append(line2)
#        
#        fig.savefig('R'+str(bin_rounds[0])+'P'+str(bin_steps[ss])+' - Caminho_' + str(ss+1) +'.png')    
#        
#        
###############################################################################
### Plottting a path instance for each step range of the least number of rounds
#               
#print("choosing the paths for each round range of a similar number of steps... ")
#
## daux selects all the range of paths in the least number of rounds 
#daux = []
#for dd in bin_paths2[0]:
#    if dd > 0:
#        daux.append(dd)
#
## nstep will be the index of the greatest range of paths and will be used to 
## choose a sample in each round range
#nstep = len(daux)-1 
# 
#selection2 = []
#
#for br in bin_rounds:
#    count = 0
#    for ap in all_paths:    
#        if ap.get('steps') == bin_steps[nstep] and ap.get('rounds') == br and count == 0:
#               selection2.append(ap.get('path'))
#               count +=1
#               
#ypaths2 = [] # it will store the y progression of all paths in selection2
#xpaths2 = [] # it will store the x progression of all paths in selection2
#
#for sample in selection2:
#   ydata = [[] for _ in range(n)] # it will store the y position of each car in each path
#   xdata = [[] for _ in range(n)] # it will store the y position of each car in each path
#
#   for nn in range(n):
#         fx = []
#         fy = []
#         for icl in sample:
#                 fx.append(markings[int(icl)][0][nn])
#                 fy.append(markings[int(icl)][1][nn])
#         while fx[-1] == 7:
#             fx.pop(-1)
#         while fy[-1] == 7:
#             fy.pop(-1)
#         xdata[nn].append(fx)
#         ydata[nn].append(fy)
#
#   xpaths2.append(xdata)
#   ypaths2.append(ydata)
#
## Concatenating the x and y position of the selected paths in order to plot
## different figures
#   
#
#for ss in range(len(selection2)):    
#   # Settting the x,y positions
#   xxdata = []
#   yydata = []
#   
#   for nn in range(n):       
#        
#        xxdata.append(xpaths2[ss][nn][0])                 
#        yydata.append(ypaths2[ss][nn][0])
#       
#   fig, axes = plt.subplots(sp1,sp2, sharex=True, sharey=True, figsize=(30,15))
#   for i, ax in enumerate(axes.flatten()):
#        # Plotting 
#        ax.plot(xxdata[i],yydata[i],marker= 's', ms = 10)
#        # Adding the final state 
#        ax.plot(xxdata[i][-1],yydata[i][-1],marker= 's', mfc = 'black', ms = 10,label='Posição final')
#        # Adding legends
#        leg = ax.legend(loc='upper left')
#                      
#        # Setting the forbidden cells (sidewalks)
#        # Setting plot limits                     
#        ax.set_xlim([-0.5, 7.5])
#        ax.set_ylim([-0.5, 7.5])
#        # Setting the forbidden cells (sidewalks)
#        rectangle1 = plt.Rectangle((-0.5, -0.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle1)
#        rectangle2 = plt.Rectangle((5.5, -0.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle2)
#        rectangle3 = plt.Rectangle((-0.5, 5.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle3)
#        rectangle4 = plt.Rectangle((5.5, 5.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle4)
#        ax.invert_yaxis()
#        fig.suptitle('Caminho ' + str(ss+1) + ' - Número de rodadas: ' + str(bin_rounds[ss]) + \
#                     '. Número de passos: ' + str(bin_steps[nstep]), fontsize=30)
#        ax.title.set_text('. Carro: ' +str(i+1))
#        
#        # Setting grid lines
#        for il in range(7):
#            line = Line2D([0.5+il, 0.5+il], [-0.5, 7.5], linestyle = '--', linewidth = 1, \
#                              color = [0,0,0], zorder = 1, transform = ax.transData)
#            line2 = Line2D([-0.5, 7.5], [0.5+il, 0.5+il], linestyle = '--', linewidth = 1, \
#                              color = [0,0,0], zorder = 1, transform = ax.transData)
#            ax.lines.append(line)
#            ax.lines.append(line2)
#        
#        fig.savefig('P'+str(bin_steps[nstep])+'R'+str(bin_rounds[ss])+' - Caminho_' + str(ss+1) +'.png')    
#        
##############################################################################
## Plotting the step distribution for the path with fewer turns and for the path with more turns  - heat map  
#print("Plotting the step distribution for the path with fewer turns and for the path with more turns  (heat map)... ")
#
#selection3 = []
#selection4 = []
#
#for ap in all_paths:    
#  if ap.get('rounds') == bin_rounds[0]:
#     selection3.append(ap.get('path'))
#  if ap.get('rounds') == bin_rounds[-1]:
#     selection4.append(ap.get('path'))
#               
### Heat map for selection3
#         
#for rr in range (n):
#    
#    xx = [] # it will stack the x position of each car in each path    
#    yy = [] # it will stack the y position of each car in each path
#    
#    for sample in selection3:  
#         fx = []
#         fy = []
#         for icl in sample:
#                 fx.append(markings[int(icl)][0][rr])
#                 fy.append(markings[int(icl)][1][rr])
#         while fx[-1] == 7:
#             fx.pop(-1)
#         while fy[-1] == 7:
#             fy.pop(-1)
#         xx.extend(fx)
#         yy.extend(fy)
#    
#    plt.figure(figsize=(15,12))
#    #plt.rcParams['figure.figsize'] = (10,12) 
#    
#    # Setting grid lines
#    c   = 0
#    while c < 7:
#    
#        line = plt.Line2D((0.5+c, 0.5+c), (-0.5, 7.5), lw=1.0, ls='--', color='k')
#        plt.gca().add_line(line)
#        c = c + 1
#
#    d = 0
#    while d < 7:
#        line = plt.Line2D((-0.5, 7.5), (0.5+d, 0.5+d), lw=1.0, ls='--', color='k')
#        plt.gca().add_line(line)
#        d = d + 1
#    
#    # Setting plot limits                     
#    plt.xlim(-0.5, 7.5)
#    plt.ylim(-0.5, 7.5)
#    
#    # Setting plot legends          
#    ff, = plt.plot(m0[0][rr],m0[1][rr],'Xr', ms = 24)
#    plt.legend([ff], ["Posição inicial"],loc='upper left', fontsize=15)
#    
#    # Setting the forbidden cells (sidewalks)
#    rectangle1 = plt.Rectangle((-0.5, -0.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle1)
#    rectangle2 = plt.Rectangle((5.5, -0.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle2)
#    rectangle3 = plt.Rectangle((-0.5, 5.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle3)
#    rectangle4 = plt.Rectangle((5.5, 5.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle4)
#    plt.gca().invert_yaxis()    
#              
#    h = plt.hist2d(xx, yy, bins=8, range = [[-0.5,7.5],[-0.5,7.5]], cmap=plt.cm.OrRd)   
#       
#    
#    plt.suptitle('Mapa de calor para o carro ' + str(rr+1), x = 0.435, y=1.0, fontsize=24)
#    plt.title('Amostras: ' + str(len(selection3)) + '. Nº de rodadas: ' + str(bin_rounds[0]), y = 1.0, fontsize=20)
#    cbar = plt.colorbar(h[3])
#    cbar.ax.set_title('Frequência',  size= 20)
#    cbar.ax.tick_params(labelsize=12)
#    cbar.ax.yaxis.set_major_locator(MaxNLocator(integer=True))
#    cbar.ax.yaxis.set_major_formatter(tick.FormatStrFormatter('%.0f'))
#    plt.gca().invert_yaxis()
#    plt.draw()
#    plt.savefig('R'+str(bin_rounds[0])+' - Mapa de calor para o carro ' + str(rr+1) +'.png')
#    print('Mapa de calor para o carro ' + str(rr+1) + ': OK')
#
#selection3 = []
#
### Heat map for selection4
#         
#for rr in range (n):
#    
#    xx = [] # it will stack the x position of each car in each path    
#    yy = [] # it will stack the y position of each car in each path
#    
#    for sample in selection4:  
#         fx = []
#         fy = []
#         for icl in sample:
#                 fx.append(markings[int(icl)][0][rr])
#                 fy.append(markings[int(icl)][1][rr])
#         while fx[-1] == 7:
#             fx.pop(-1)
#         while fy[-1] == 7:
#             fy.pop(-1)
#         xx.extend(fx)
#         yy.extend(fy)
#    
#    plt.figure(figsize=(15,12))
#    #plt.rcParams['figure.figsize'] = (10,12) 
#    
#    # Setting grid lines
#    c   = 0
#    while c < 7:
#    
#        line = plt.Line2D((0.5+c, 0.5+c), (-0.5, 7.5), lw=1.0, ls='--', color='k')
#        plt.gca().add_line(line)
#        c = c + 1
#
#    d = 0
#    while d < 7:
#        line = plt.Line2D((-0.5, 7.5), (0.5+d, 0.5+d), lw=1.0, ls='--', color='k')
#        plt.gca().add_line(line)
#        d = d + 1
#    
#    # Setting plot limits                     
#    plt.xlim(-0.5, 7.5)
#    plt.ylim(-0.5, 7.5)
#    
#    # Setting plot legends          
#    ff, = plt.plot(m0[0][rr],m0[1][rr],'Xr', ms = 24)
#    plt.legend([ff], ["Posição inicial"],loc='upper left', fontsize=15)
#    
#    # Setting the forbidden cells (sidewalks)
#    rectangle1 = plt.Rectangle((-0.5, -0.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle1)
#    rectangle2 = plt.Rectangle((5.5, -0.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle2)
#    rectangle3 = plt.Rectangle((-0.5, 5.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle3)
#    rectangle4 = plt.Rectangle((5.5, 5.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle4)
#    plt.gca().invert_yaxis()    
#              
#    h = plt.hist2d(xx, yy, bins=8, range = [[-0.5,7.5],[-0.5,7.5]], cmap=plt.cm.OrRd)   
#       
#    
#    plt.suptitle('Mapa de calor para o carro ' + str(rr+1), x = 0.435, y=1.0, fontsize=24)
#    plt.title('Amostras: ' + str(len(selection4)) + '. Nº de rodadas: ' + str(bin_rounds[-1]), y = 1.0, fontsize=20)
#    cbar = plt.colorbar(h[3])
#    cbar.ax.set_title('Frequência',  size= 20)
#    cbar.ax.tick_params(labelsize=12)
#    cbar.ax.yaxis.set_major_locator(MaxNLocator(integer=True))
#    cbar.ax.yaxis.set_major_formatter(tick.FormatStrFormatter('%.0f'))
#    plt.gca().invert_yaxis()
#    plt.draw()
#    plt.savefig('R'+str(bin_rounds[-1])+' - Mapa de calor para o carro ' + str(rr+1) +'.png')
#    print('Mapa de calor para o carro ' + str(rr+1) + ': OK')
#
#selection4 = []
##############################################################################
## Plotting the step distribution for the paths with more steps - heat map  
#print("Plotting the step distribution for the paths with more turns  (heat map)... ")
#
#selection5 = []
#
#for ap in all_paths:    
#  if ap.get('steps') == bin_steps[-1]:
#     selection5.append(ap.get('path'))
#               
### Heat map for selection3
#         
#for rr in range (n):
#    
#    xx = [] # it will stack the x position of each car in each path    
#    yy = [] # it will stack the y position of each car in each path
#    
#    for sample in selection5:  
#         fx = []
#         fy = []
#         for icl in sample:
#                 fx.append(markings[int(icl)][0][rr])
#                 fy.append(markings[int(icl)][1][rr])
#         while fx[-1] == 7:
#             fx.pop(-1)
#         while fy[-1] == 7:
#             fy.pop(-1)
#         xx.extend(fx)
#         yy.extend(fy)
#    
#    plt.figure(figsize=(15,12))
#    #plt.rcParams['figure.figsize'] = (10,12) 
#    
#    # Setting grid lines
#    c   = 0
#    while c < 7:
#    
#        line = plt.Line2D((0.5+c, 0.5+c), (-0.5, 7.5), lw=1.0, ls='--', color='k')
#        plt.gca().add_line(line)
#        c = c + 1
#
#    d = 0
#    while d < 7:
#        line = plt.Line2D((-0.5, 7.5), (0.5+d, 0.5+d), lw=1.0, ls='--', color='k')
#        plt.gca().add_line(line)
#        d = d + 1
#    
#    # Setting plot limits                     
#    plt.xlim(-0.5, 7.5)
#    plt.ylim(-0.5, 7.5)
#    
#    # Setting plot legends          
#    ff, = plt.plot(m0[0][rr],m0[1][rr],'Xr', ms = 24)
#    plt.legend([ff], ["Posição inicial"],loc='upper left', fontsize=15)
#    
#    # Setting the forbidden cells (sidewalks)
#    rectangle1 = plt.Rectangle((-0.5, -0.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle1)
#    rectangle2 = plt.Rectangle((5.5, -0.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle2)
#    rectangle3 = plt.Rectangle((-0.5, 5.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle3)
#    rectangle4 = plt.Rectangle((5.5, 5.5), 2, 2, fc='gray')
#    plt.gca().add_patch(rectangle4)
#    plt.gca().invert_yaxis()    
#              
#    h = plt.hist2d(xx, yy, bins=8, range = [[-0.5,7.5],[-0.5,7.5]], cmap=plt.cm.OrRd)   
#       
#    
#    plt.suptitle('Mapa de calor para o carro ' + str(rr+1), x = 0.435, y=1.0, fontsize=24)
#    plt.title('Amostras: ' + str(len(selection5)) + '. Nº de passos: ' + str(bin_steps[-1]), y = 1.0, fontsize=20)
#    cbar = plt.colorbar(h[3])
#    cbar.ax.set_title('Frequência',  size= 20)
#    cbar.ax.tick_params(labelsize=12)
#    cbar.ax.yaxis.set_major_locator(MaxNLocator(integer=True))
#    cbar.ax.yaxis.set_major_formatter(tick.FormatStrFormatter('%.0f'))
#    plt.gca().invert_yaxis()
#    plt.draw()
#    plt.savefig('P'+str(bin_steps[-1])+' - Mapa de calor para o carro ' + str(rr+1) +'.png')
#    print('Mapa de calor para o carro ' + str(rr+1) + ': OK')
#
#selection5 = []  
#
###############################################################################
### Counting the number of lane changes for each path   
#print("Counting the number of lane changes for each path ... ")
#
#selection6 = []
#
#for ap in all_paths:    
#  if ap.get('steps') == bin_steps[0]:
#     selection6.append(ap.get('path'))
#               
#
#ypaths3 = [] # stores the y progression of all paths
#xpaths3 = [] # stores the x progression of all paths
#sumcount = [] # counts the lane changes in each path
#
#for sample in selection6:
#   ydata = [[] for _ in range(n)] # stores the y position of each car in each path
#   xdata = [[] for _ in range(n)] # stores the y position of each car in each path
#   countn = []
#   for nn in range(n):
#         fx = []
#         fy = []
#         for icl in sample:
#                 fx.append(markings[int(icl)][0][nn])
#                 fy.append(markings[int(icl)][1][nn])
#         while fx[-1] == 7:
#             fx.pop(-1)
#         while fy[-1] == 7:
#             fy.pop(-1)
#        
#         lenxy = len(fx) # paths length
#         if init_list[nn] == 1 or init_list[nn] == 3: #vertical roads
#            counter = 0
#            for ii in range(lenxy-1):
#                if fx[ii] != fx[ii+1]:
#                    counter += 1
#            countn.append(counter) # append the number of lane changes for each vertical path
#       
#         if init_list[nn] == 2 or init_list[nn] == 4: #horizontal roads
#            counter = 0
#            for ii in range(lenxy-1):
#                if fy[ii] != fy[ii+1]:
#                    counter += 1
#            countn.append(counter)
#         xdata[nn].append(fx)
#         ydata[nn].append(fy)
#         
#   sumcount.append(sum(countn))
#   xpaths3.append(xdata)
#   ypaths3.append(ydata)
#
## putting the list of bins in order of number of changes
#bin_changes = list(set(sumcount)) 
#bin_changes.sort()
#
## counting the number of paths for each number of lane changes
#bin_paths3 = list(dict(Counter(sumcount)).values())
#
###############################################################################
### Plotting the lane chanes distributions  
#print("Plotting the lane chanes distribution ... ")
#
#df3 = pd.DataFrame({"Nº de caminhos": bin_paths3}, index=bin_changes)
#ax = df3.plot(kind="bar", fontsize = 20)
#for p in ax.patches:
#    ax.annotate("%.f" % p.get_height(), (p.get_x() + p.get_width() / 2., \
#    p.get_height()), fontsize=20, ha='center', va='center', xytext=(0, 20), \
#        textcoords='offset points')  
#plt.yscale('log')
#plt.xticks(rotation=30, horizontalalignment="center")
#plt.title("Distribuição dos menores caminhos por número de mudanças de faixa",fontsize=30)
#plt.xlabel("Número de mudanças de faixas", fontsize=25)
#plt.ylabel("Número de caminhos (escala logarítmica)", fontsize=25)
#plt.legend(fontsize=15,loc='upper left')
#plt.savefig('Gráfico de Barras - Distribuição de caminhos (menos passos) por mudanças de faixas.png', bbox_inches = 'tight')
#
## selecting the paths with fewer lane changes
#best_paths = [selection6[i] for i,s in enumerate(sumcount) if s == bin_changes[0]]
#
#for ss in range(len(best_paths)):    
#   # Settting the x,y positions
#   xxdata = []
#   yydata = []
#   
#   for nn in range(n):       
#        
#        xxdata.append(xpaths[ss][nn][0])                 
#        yydata.append(ypaths[ss][nn][0])
#       
#   fig, axes = plt.subplots(sp1,sp2, sharex=True, sharey=True, figsize=(30,15))
#   for i, ax in enumerate(axes.flatten()):
#        # Plotting 
#        ax.plot(xxdata[i],yydata[i],marker= 's', ms = 10)
#        # Adding the final state 
#        ax.plot(xxdata[i][-1],yydata[i][-1],marker= 's', mfc = 'black', ms = 10,label='Posição final')
#        # Adding legends
#        leg = ax.legend(loc='upper left')
#                      
#        # Setting the forbidden cells (sidewalks)
#        # Setting plot limits                     
#        ax.set_xlim([-0.5, 7.5])
#        ax.set_ylim([-0.5, 7.5])
#        # Setting the forbidden cells (sidewalks)
#        rectangle1 = plt.Rectangle((-0.5, -0.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle1)
#        rectangle2 = plt.Rectangle((5.5, -0.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle2)
#        rectangle3 = plt.Rectangle((-0.5, 5.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle3)
#        rectangle4 = plt.Rectangle((5.5, 5.5), 2, 2, fc='gray')
#        ax.add_patch(rectangle4)
#        ax.invert_yaxis()
#        fig.suptitle('Caminho ' + str(ss+1) + ' - Número de mudanças de faixa: ' \
#                     + str(bin_changes[0]), fontsize=30)
#        ax.title.set_text('. Carro: ' +str(i+1))
#        
#        # Setting grid lines
#        for il in range(7):
#            line = Line2D([0.5+il, 0.5+il], [-0.5, 7.5], linestyle = '--', linewidth = 1, \
#                              color = [0,0,0], zorder = 1, transform = ax.transData)
#            line2 = Line2D([-0.5, 7.5], [0.5+il, 0.5+il], linestyle = '--', linewidth = 1, \
#                              color = [0,0,0], zorder = 1, transform = ax.transData)
#            ax.lines.append(line)
#            ax.lines.append(line2)
#        
#        fig.savefig('M'+str(bin_changes[0])+' - Caminho_' + str(ss+1) +'.png')
#


