import networkx as nx
import re
import ast
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

#INFO.TXT CONTAINS ALL THE INFORMATION ABOUT STATES AND TRANSITIONS FROM THE MODEL.

markings = []
dead_markings = []
pat1 = re.compile(": play_1_smove {play")  #defines a pattern to be found in the file.
pat2 = re.compile(": play_1_sbound {play") #defines a pattern to be found in the file.
pat3 = re.compile(": play_1_sdone {play")  #defines a pattern to be found in the file.
pat4 = re.compile("dead marking")          #defines a pattern to be found in the file.

# The following procedure is done to identify the dead markings of the model.
# First, set the path of the info.txt file
# Make sure to replace your_home_folder with your computer username 
with open ("C:\\Users\\your_home_folder\\...\\Intersection2\\info.txt", 'rt') as info:    
    for t in info: 
        # If a pattern is found, it is replaced by an empty space. 
        if pat1.search(t) != None or pat2.search(t) != None or pat3.search(t) != None:
            # After deleting unused information, the markings (states) are broken into lines 
            # (rstrip command) and added to the marking list.
            markings.append((t.rstrip('\n')))

        else: 
             if pat4.search(t) != None:
             # After deleting unused information, dead markings are broken into lines 
             # (rstrip command) and added to the dead_marking list.
                 dead_markings.append((t.rstrip('\n')))
                
                 
# maux and maux2 handle each line in markings List and extracts only the arrays.
maux  = [re.sub(r'.*va=', '', iline) for iline in markings]
maux2 = [re.sub(r'}', '', iline2) for iline2 in maux]

st =[] # Empty list

# This FOR loop transforms array strings into np.array
for l in maux2:
    maux3 = np.array(ast.literal_eval(l))
    st.append(maux3)

# This removes the unnecessary information from the DEAD MARKINGS 
# and transforms each dead marking into a list item.
daux = dead_markings[1]
daux2 = daux.translate({ord(i): None for i in "deadmarking(s):"})
daux3 = daux2.split(' ')
daux3.pop(0)
daux3.pop(0)
    
# It reads the .txt file from the .ktz file 
# to extract the information about the transitions of the Reachability Graph
reach_file = open("C:\\Users\\your_home_folder\\...\\Intersection2\\reach_graph.txt", 'r')
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
       line_up = line.translate({ord(i): None for i in '[(play_t)"]'})
       line_aux =  line_up.translate({ord(i): None for i in "'"})
       line_up2 = line_aux.split(',')
       line_up2.pop(1)
       upd_reach_list.append(line_up2)

lst = range(n_states) 
nodes = ["{:1d}".format(x) for x in lst] # stores all the states Id    

# start the composition of reachability graph
G = nx.Graph()

G.add_nodes_from(nodes) # add from "nodes" list. nodes are the states
G.add_edges_from(upd_reach_list)

print("Number of States: "+ str(G.number_of_nodes()))
print("Number of Transitions: "+ str(G.number_of_edges()))
print(" ")


for dm in daux3:
#    m = str([p for p in nx.all_shortest_paths(G, '0', dm)])
#    m2 = np.array(ast.literal_eval(m))
#    print("There "+str(len(m2))+" different shortest paths with " +\
#          str(len(nx.shortest_path(G, '0', dm))) + " states for the dead marking "\
#          + str(dm))
#    print(" ")
#    print("An example of shortest path for the dead marking " + str(dm) + " is "\
#    + str(nx.shortest_path(G, '0', dm))+" with " + \
#    str(len(nx.shortest_path(G, '0', dm)))+" states")
#    print(" ")
   
    # Stores the states that make up the shortest path in a list
    shortest_path = nx.shortest_path(G, '0', dm) 
    shortest_path.pop(0)
    # Add the initial state from the System to a vector that will be updated
    image_vector = st[0] 
    
    for k in shortest_path:
        s_index = nodes.index(k)
        image_vector = np.vstack((image_vector,st[s_index]))
    
    b=np.split(image_vector, len(shortest_path)+1)

#transforms each state / transition into image
 
    fig, ax = plt.subplots()

    frame = 0
    matrice = ax.imshow(b[0])
    
    def update(i):
        value=b[i]
        matrice.set_array(value)
    
    ani = animation.FuncAnimation(fig, update, len(b))
    mywriter = animation.FFMpegWriter(fps=4)
    ani.save('dead_marking_'+str(dm)+'.mp4',writer=mywriter)


