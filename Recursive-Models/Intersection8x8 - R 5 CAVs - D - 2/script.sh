#!/bin/bash

echo "Fiacre Builder"
echo "Project name: $1" 

project=$1

FIACREPATH=/opt/frac-2.5.0

rm -rf ${project}.tts
rm ${project}.ktz
frac ${project}.fcr ${project}.tts
make -f ${FIACREPATH}/Makefile ${project}
tina ${project}.tts ${project}.ktz
tina ${project}.tts ${project}.aut
tina -d ${project}.tts > info.txt
selt ${project}.ktz ${project}.tts/${project}.ltl -b -S ${project}.scn
cat ${project}.aut>reach_graph.txt
#cat ${project}.scn>counter_example.txt
#fmt -1 counter_example.txt > step.txt
#sed '$d' step.txt