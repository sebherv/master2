#!/bin/bash

exec 3>&2
exec 2> /dev/null

for val in 100 1000 10000 20000 40000 80000
do
	mpirun -hostfile hosts -np 4 ./is_prime value $val mode_block
	mpirun -hostfile hosts -np 4 ./is_prime value $val mode_cyclic
done

exec 2>&3