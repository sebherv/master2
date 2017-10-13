#!/bin/bash

exec 3>&2
exec 2> /dev/null

for m in 10 50 100 500 1000 5000
	do
	for n in {200..5000..200}
		do
			mpirun -hostfile hosts -np 4 ./boucle numFloats $n numRings $m 
	done
	for n in {5000..50000..5000}
		do
			mpirun -hostfile hosts -np 4 ./boucle numFloats $n numRings $m 
	done
done

exec 2>&3