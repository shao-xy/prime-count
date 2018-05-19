#!/bin/bash

make
mpirun -np $2 main $1
