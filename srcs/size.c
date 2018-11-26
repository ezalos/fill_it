/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:34:44 by anonymou          #+#    #+#             */
/*   Updated: 2018/11/26 21:37:42 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		size_square(int p)
{
	return (float_to_int(f_sqrt(p, 0) * 2));
}

int		size_pieces(char *s, int size)
{
	if (*s == O)
		return ((size - 1) * (size - 1));
	else if (*s == I)
		return ((size - 3) * size);
	else
		return ((size - 1) * (size - 2));
}
