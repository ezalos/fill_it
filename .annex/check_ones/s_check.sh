# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    s_check.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 04:57:48 by ldevelle          #+#    #+#              #
#    Updated: 2019/01/18 04:57:49 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#./a.out tests/26_good.fillit | grep "	1" > test
grep "	1" > test
cat test | cut -d  ">" -f 2 > test2
cat test2 | tr -d "0" > test
#cat test | cut -c 5- > test2
cat -n test > result
rm test test2
cat result
