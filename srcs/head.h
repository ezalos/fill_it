/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:30:33 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/27 05:36:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

#include <stdio.h>
#include <string.h>
#include <time.h>

char		*ft_read_check(char *fillit);
const char	*recognize(char *s);
int			float_to_int(float i);
float		f_sqrt(int nb, int limite);
int			size_square(int p);
int			size_pieces(char *s, int size);

#endif
