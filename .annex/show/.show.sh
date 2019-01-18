# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    .show.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 04:57:33 by ldevelle          #+#    #+#              #
#    Updated: 2019/01/18 04:57:35 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

#grep -n  printf ../*.c >> .gres.txt			= to input all lines numbered with printf from previous dir files into .gres.txt;
#cut -d ':' -f1 .gres.txt | sort -u				= to get each file listed only once;
#sed 's/.*printf.*//' <file> 					= to transform lines containing printf to blank lines;
#sed -i '' '/printf/d' <file>					= to remove lines containing printf;
#diff -a --suppress-common-lines -y a.txt b.txt	= compare two files, input non-identical lines


declare -i i=0
while IFS=: read -r line target lno str
do
{
file[$i]="$(cut -d ':' -f1 <<< $line)"
line_nb[$i]="$(cut -d ':' -f2 <<< $line)"
str="${str//\\/\\\\}"
string[$i]="$(cut -d ':' -f3 <<< $line)"
((i++))
}
done < .gres.txt

#declare -i i=0
#if [ wc -l $target -g $lno ]; then
#	sed -e


declare -i i=0
while IFS=: read -r target lno str
do	file[i]="$target"
	line_nb[i]="$lno"
	str="${str//\\/\\\\}"
	string[i++]="$str"
	sed -i '' "$lno i\\
	$str" $target
	i=$[$i + 1]
done < .gres.txt
