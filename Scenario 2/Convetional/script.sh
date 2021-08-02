#!/bin/bash

echo "Fiacre Builder"
echo "Project name: $1" 

project=$1

FIACREPATH=/mnt/c/Users/PC/Documents/Formal_Verification_CAVs/frac-2.5.0

rm -rf ${project}.tts
rm ${project}.ktz
frac ${project}.fcr ${project}.tts
make -f ${FIACREPATH}/Makefile ${project}
tina ${project}.tts ${project}.aut>${project}.ktz
tina ${project}.tts > info.txt
selt ${project}.ktz ${project}.tts/${project}.ltl -b 
cat ${project}.aut>reach_graph.txt
cat ${project}.fcr>init.txt
sed -i '/GRAPH:/,$d;s/intersection_1_//g;/smove/s/^.*x=//;s/sdone {//g;s/vpy=//g;s/vpx=//g;/dead/d;s/,vlm.*$//;1,/MARKINGS/d;s/vt//g;s/,vsn=//g;/^$/d' info.txt
sed -i '/des/d;s/intersection_1_t//g;s/"//g' reach_graph.txt
sed -i '/intersection/d;' ${project}.aut
sed -i '/flag_2/,$d;1,/flag_1/d;s/const v : Cars is //g' init.txt