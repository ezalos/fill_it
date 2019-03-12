/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 01:03:10 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/17 01:27:29 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef	struct		s_hash
{
	struct t_list	*board;
	uintmax_t		size_board;
	//intmax_t		key;
	//void			*content;
	//size_t			content_size;
	struct s_list	*next;
}					t_hash;

int		lets_class_it(intmax_t key, void *content, size_t size)
{
	static t_hash	*H;
	int				i;

	i = 0;

	return ();
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);

	return (0);
}
