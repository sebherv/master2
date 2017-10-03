#!/bin/bash

exec 3>&2
exec 2> /dev/null

for m in 10 50 100 500 1000 5000
	do
	for n in {100..5000..100}
		do
			mpirun -hostfile hosts -np 2 ./pingpong pingN $n pingM $m 
	done
	for n in {5000..50000..1000}
		do
			mpirun -hostfile hosts -np 2 ./pingpong pingN $n pingM $m 
	done
done

exec 2>&3