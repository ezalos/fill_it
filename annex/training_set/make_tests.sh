#!/bin/bash

n=1
nb_pieces=0
piece=0
i=0

#the number after -lt in the first while indicates the number of tests you want to generate

while [[ n -lt 1000 ]]; do
	nb_pieces=$[ ( RANDOM % 26 )  + 1 ]
	i=0
	while [[ $i -lt $nb_pieces ]]; do
		piece=$[ ( RANDOM % 19  ) + 1 ]
		echo -e "$(<pieces/p$piece)" >> pre$n
		i=$[$i + 1]
	done
	awk -v n=4 '1; NR % n == 0 {print ""; }' pre$n > test$n
	rm -rf pre*
	sed -i '' '$d' test$n
	n=$[$n + 1]
done

mkdir tests
mv test* tests/
