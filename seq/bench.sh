#!/bin/bash

for i in 1000 10000 100000 500000; do
	echo -e "\e[1;33mSize = $i\e[0m"
	./main $i
done
