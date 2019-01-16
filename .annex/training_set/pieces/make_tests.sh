#!/bin/bash

n=1
nb_pieces=0
piece=0
i=0

while [[ n -lt 10 ]]; do
	nb_pieces=$[ ( RANDOM % 26 )  + 1 ]
	#echo $nb_pieces
	i=0
	while [[ $i -lt $nb_pieces ]]; do
		piece=$[ ( RANDOM % 19  ) + 1 ]
		#echo $piece
		echo -e "$(<p$piece)" >> test$n
		i=$[$i + 1]
	done
#	sed 'N;s/.*/&\/\n/' test$n
#	awk '{ if ((NR % 4) == 0) printf("\n"); print; }'
#	cat test$n | xargs -n 4 -d | sed 's/ /,/g'
	n=$[$n + 1]

done
