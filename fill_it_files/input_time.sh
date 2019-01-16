#!/bin/bash

ls *.c >> list_files.txt

declare -i i=0
while IFS=: read -r line
do
{
	perl -0777 -pe 's {\)\n\{} {$& \n\ttime_exe(__func__, cl(clock());}g' $line >> temp.c
	rm $line
	cat temp.c >> $line
	rm temp.c
}
done < list_files.txt

rm list_files.txt
