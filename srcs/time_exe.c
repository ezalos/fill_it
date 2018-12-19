/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:52:19 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/20 00:29:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time_exe.h>

/*

	time_exe("NAME OF PROGRAM", clock())


time_exe(__func__, clock());


	clock_t	t = clock();
 */

void	print_time(t_time *time)
{
	t_time		*tmp;
	double		total;

	total = 0;
	tmp = time;
	while (tmp)
	{
		total += (double)tmp->t;
		tmp = tmp->next;
	}

	tmp = time;
	while (tmp)
	{
		printf(_CYAN "%f\%\t%s\n\t\t\ttook %f seconds to execute \n" _RESET, ((double)t)/total, s, ((double)*t)/CLOCKS_PER_SEC);
		tmp = tmp->next;
	}
}

t_time	*time_link_creation(t_time **time, const char* s, clock_t t)
{
	if(!((*time) = (t_time*)malloc(sizeof(t_time))))
		return (NULL);
	(*time)->name = ft_strdup(s);
	(*time)->t = t;
	(*time)->next = NULL;
	return(*time);
}

t_time	*time_exe(const char* s, clock_t t)
{
	static t_time	*time;
	t_time			*tmp;
	static clock_t	origin = clock();
	static clock_t	latest;

	if (s == NULL)
	{
		latest = t;
		return (NULL);
	}
	if (!time)
	{
		t -= origin;
		time_link_creation(&time, s, t);
		latest = t;
		return (time);
	}

	t -= latest;
	tmp = time;
	while (tmp)
	{
		if (ft_strstr(s, tmp->name))
		{
			tmp->t += t;
			latest = t;
			return (time);
		}
		tmp = tmp->next;
	}
	time_link_creation(&time, s, t);
	latest = t;
	return (time);
}
