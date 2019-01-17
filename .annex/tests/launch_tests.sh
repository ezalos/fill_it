i=0
while [[ $i -lt $2 ]]; do
	echo './fillit ./.annex/tests/random_generated/test'$i
	./$1 ./.annex/tests/random_generated/test$i
	i=$[$i + 1]
	echo ' '
done
