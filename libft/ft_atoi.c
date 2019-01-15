/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:53 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/11 20:42:28 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *src)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (((src[i] >= 8 && src[i] <= 13) || src[i] == ' ') && src[i])
		i++;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
			sign = -1;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
		res = res * 10 + src[i++] - 48;
	return (res * sign);
}
