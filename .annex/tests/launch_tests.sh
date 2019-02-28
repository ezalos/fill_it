# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    launch_tests.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 04:57:25 by ldevelle          #+#    #+#              #
#    Updated: 2019/02/28 11:50:23 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
i=0
while [[ $i -lt $2 ]]; do
	echo './fillit ./.annex/tests/random_generated/test'$i
	./$1 ./.annex/tests/random_generated/test$i
	i=$[$i + 1]
	echo ' '
done
