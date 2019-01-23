#!/bin/bash

n=0
nb_pieces=0
piece=0
i=0
choose=$[ ( RANDOM % 6 ) + 1 ]
declare prompt
<<<<<<< HEAD

if [ \( "$2" -lt "1" \) -o \( "$1" -lt "1" \) ];then
	if [ \( "$choose" == 1 \) ];then
		prompt="-----> with: (n >= 1 && p >= 1)";
	elif [ \( "$choose" == 2 \) ];then
		prompt="pls think about a valid number";
	elif [ \( "$choose" == 3 \) ];then
		prompt="come on dude just stop doing that";
	elif [ \( "$choose" == 4 \) ];then
		prompt="r u serious?";
	elif [ \( "$choose" == 5 \) ];then
		prompt="rly bro?";
	elif [ \( "$choose" == 6 \) ];then
		prompt="did you just...?";
	fi
	echo "[..]"
	sleep 1
	echo "[...]"
	sleep 1
	if [ \( "$choose" == 1 \) ];then
		echo "usage: make testa p=y n=x"
	fi
	echo $prompt
	exit
fi

=======

if [ \( "$2" -lt "1" \) -o \( "$1" -lt "1" \) ];then
	if [ \( "$choose" == 1 \) ];then
		prompt="usage: make testa p=y n=x\nwith n >= 1 && p >= 1";
	elif [ \( "$choose" == 2 \) ];then
		prompt="pls think about a valid number";
	elif [ \( "$choose" == 3 \) ];then
		prompt="come on dude just stop doing that";
	elif [ \( "$choose" == 4 \) ];then
		prompt="r u serious?";
	elif [ \( "$choose" == 5 \) ];then
		prompt="rly bro?";
	elif [ \( "$choose" == 6 \) ];then
		prompt="did you just...?";
	fi
	echo "[..]"
	sleep 1
	echo "[...]"
	sleep 1
	echo $prompt
	exit
fi 
	
>>>>>>> efcdbc5831f031b3bbbaf3bf5bebbd893f810b7a

while [[ n -lt $2 ]]; do
	nb_pieces=$[($1)]
	i=0
	while [[ $i -lt $nb_pieces ]]; do
		piece=$[ ( RANDOM % 19  ) + 1 ]
		echo -e "$(<.annex/training_set/pieces/p$piece)" >> pre$n
		i=$[$i + 1]
	done
	awk -v n=4 '1; NR % n == 0 {print ""; }' pre$n > test$n
	rm -rf pre*
	sed -i '' '$d' test$n
	n=$[$n + 1]
done

mv test* .annex/tests/random_generated
