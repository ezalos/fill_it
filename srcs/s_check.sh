#./a.out tests/26_good.fillit | grep "	1" > test
grep "	1" > test
cat test | cut -d  ">" -f 2 > test2
cat test2 | tr -d "0" > test
#cat test | cut -c 5- > test2
cat -n test > result
rm test test2
cat result
