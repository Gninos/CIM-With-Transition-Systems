import networkx as nx
import re
import ast
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


# The following procedure is done to identify the dead markings of the model.
# "pat" defines a pattern to be found in the file.
markings = []
dead_markings = []
pat1 = re.compile(": intersection_1_smove {intersection")  
pat2 = re.compile(": intersection_1_sdone {intersection")  

# First, set the path of the info.txt file.
# Make sure to replace your_home_folder with your computer username 
with open ("C:\\Users\\Acer\\Google Drive\\UFSC\\Dissertação\\Fiacre Exemplos\\exemplos atuais\\Intersection2 - 4 CAVs R\\info.txt", 'rt') as info:    
    for t in info: 
        # If a pattern 'pat1 is found, the item is defined as a marking (state)
        if pat1.search(t) != None :
            # the markings are broken into lines 
            # (rstrip command) and added to the marking list.
            markings.append((t.rstrip('\n')))
            

        else:  # If a pattern 'pat2' is found, the item is defined as 
               # a dead marking, and also added to markings list
             if pat2.search(t) != None:
                 markings.append((t.rstrip('\n')))
                 dead_markings.append((t.rstrip('\n')))
                 print("Final state found")
                 
# maux and maux2 handle each line in markings List and extracts only the arrays.
maux  = [re.sub(r'.*va=', '', iline) for iline in markings]
maux2 = [re.sub(r'}', '', iline2) for iline2 in maux]

st =[] # Empty list

# This FOR loop transforms array strings into np.array
for l in maux2:
    maux3 = np.array(ast.literal_eval(l))
    st.append(maux3)

# This removes the unnecessary information from the DEAD MARKING 
# and transforms it dead marking into a list item.
daux  = [re.sub(r' :.*', '', iline) for iline in dead_markings]
target = daux[0]


# It reads the .txt file from the .ktz file 
# to extract the information about the transitions of the Reachability Graph
reach_file = open("C:\\Users\\Acer\\Google Drive\\UFSC\\Dissertação\\Fiacre Exemplos\\exemplos atuais\\Intersection2 - 4 CAVs R\\reach_graph.txt", 'r')
reach_list = [line.strip().split(' ') for line in reach_file.readlines()]
first=reach_list[0] # this stores state and transition information in the first line
reach_list.pop(0) # delete the first line of the file now that the information is stored
upd_reach_list=[] # list to update transition values

# this treats the string "first" and selects the number of states
states=str(first);
states_1 = states.translate({ord(i): None for i in '[(des)]'})
states_2 = states_1.translate({ord(i): None for i in "'"})
states_3 = states_2.split(',')
states_3.pop(0)
states_3.pop(0)
n_states= int(states_3[0]) # stores total number of states


# This treats transitions to be read in networkx 
for row in reach_list:

       line=str(row); 
       line_up = line.translate({ord(i): None for i in '[(intersection_t)"]'})
       line_aux =  line_up.translate({ord(i): None for i in "'"})
       line_up2 = line_aux.split(',')
       line_up2.pop(1)
       upd_reach_list.append(line_up2)

# start the composition of reachability graph

lst = range(n_states) 
nodes = ["{:1d}".format(x) for x in lst] # stores all the states Id    


G = nx.Graph()
# add the nodes of the graph from "nodes" list. nodes are the states
G.add_nodes_from(nodes)
# add the edges of the graph from "upd_reach_list" list. edges are the transitions
G.add_edges_from(upd_reach_list) 

print("Number of States: "+ str(G.number_of_nodes()))
print("Number of Transitions: "+ str(G.number_of_edges()))
print(" ")


# Generate only one animation
shortest_path = nx.shortest_path(G, '0', target) 
shortest_path.pop(0)

image_vector = st[0] 

for k in shortest_path:
        s_index = nodes.index(k)
        image_vector = np.vstack((image_vector,st[s_index]))
    
b=np.split(image_vector, len(shortest_path)+1)

  
fig, ax = plt.subplots()

frame = 0
matrice = ax.imshow(b[0])
    
def update(i):
     value=b[i]
     matrice.set_array(value)
    
ani = animation.FuncAnimation(fig, update, len(b))
mywriter = animation.FFMpegWriter(fps=4)
ani.save('dead_marking_'+str(target)+'.mp4',writer=mywriter)




