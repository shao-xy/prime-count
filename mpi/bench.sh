#!/bin/bash

for i in 1000 10000 100000 500000; do
	for j in 1 2 4 8 16 32; do
		echo -e "\e[1;33mSize = $i Proc_num = $j\e[0m"
		./run.sh $i $j
	done
done
