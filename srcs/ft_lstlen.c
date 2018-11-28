/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:47:21 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/27 18:47:22 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lstlen(t_list *begin_list)
{
	int		i;

	i = 0;
	if (begin_list)
	{
		while (begin_list->next)
		{
			begin_list = begin_list->next;
			i++;
		}
		i++;
	}
	return (i);
}
