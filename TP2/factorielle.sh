#!/bin/bash
factorielle=1

for i in $(seq 1 $1); do
    factorielle=$(($factorielle*$i))
done 

echo $factorielle
