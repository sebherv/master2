#!/bin/bash

exec 3>&2
exec 2> /dev/null

for val in 100 1000 10000 20000 40000 80000 100000 500000
do
	mpirun -np 4 ./is_prime value $val mode_block
	mpirun -np 4 ./is_prime value $val mode_cyclic
done

exec 2>&3