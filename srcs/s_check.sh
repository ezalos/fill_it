./a.out tests/test2.fillit | grep "	:" > test
cat test | cut -d : -f 2 > test2
cat test2 | tr -d "0" > test
cat test | cut -c 5- > test2
cat -n test2 > result
rm test test2
cat result
