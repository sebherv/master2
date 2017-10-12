#!/bin/bash

exec 3>&2
exec 2> /dev/null

for m in 10 50 100 500
	do
	for n in {100..5000..100}
		do
			mpirun -np 4 ./boucle numFloats $n numRings $m 
	done
	for n in {5000..10000..1000}
		do
			mpirun -np 4 ./boucle numFloats $n numRings $m 
	done
done

exec 2>&3