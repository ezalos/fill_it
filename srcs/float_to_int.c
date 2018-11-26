/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:41:09 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/26 21:41:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		float_to_int(float i)
{
	int sol;

	if (i % 1 >= 0.5)
		sol = ((int)i / 1) + 1;
	else
		sol = (int)i / 1;
	return (sol);
}
