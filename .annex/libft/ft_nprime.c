/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:32:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/21 17:00:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_next_prime(int nb, int *prime_list)
{
	int	x;

	x = 0;
	if (nb <= 2)
		return (2);
	if (nb == 3)
		return (nb);
	while (nb <= 2147483647)
	{
		while (prime_list[x] != 0 && prime_list[x] <= nb / prime_list[x])
		{
			if (nb % prime_list[x] == 0)
			{
				nb++;
				x = -1;
			}
			x++;
		}
		return (nb);
	}
	return (0);
}

static int	*initialize(int *prime_list, int limite)
{
	int	i;

	i = 0;
	while (i <= limite)
		prime_list[i++] = 0;
	return (prime_list);
}

int			*ft_nprime(int limite)
{
	int	compteur;
	int	*prime_list;

	if (limite > 105097564)
		return (NULL);
	compteur = 0;
	if (!(prime_list = (int*)malloc((limite + 2) * sizeof(int))))
		return (NULL);
	prime_list = initialize(prime_list, limite + 1);
	prime_list[compteur] = 2;
	while (compteur++ < limite)
		prime_list[compteur] =
		ft_find_next_prime(prime_list[compteur - 1] + 1, prime_list);
	return (prime_list);
}
