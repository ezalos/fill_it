/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:52:19 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/21 12:39:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

/*
time_exe(__func__, clock());
print_time(time_exe(__func__, clock()));
*/

void 	print_time_struct(t_time *g)
{
	printf(_RED"\tAdress:\t\t%p\n", (void *)g);
 	printf("\tNAME:\t\t%s\t\tTime:%Lf\n", g->name, g->t);
 	printf("\tNEXT:\t\t%p\n" _RESET, (void*)g->next);
}

void	ft_puttab(const char *s, int separation)
{
	int tab;

	tab = ft_strlen(s);
	if (tab % 4 != 0)
		tab = (tab / 4) + 1;
	else
		tab = tab / 4;
	while (separation - tab++ > 0)
		printf("\t");
//		write(1, "\t", 1);
}

void	print_time(t_time *timee)
{
	t_time			*tmp;
	long double		total;
	int				tab;

	total = 0;
	tmp = timee;
	while (tmp)
	{
		total += (long double)tmp->t;
		tmp = tmp->next;
	}
	printf(_CYAN "Total time of program: %Lf\n" _RESET, (long double)total);

	tmp = timee;
	while (tmp)
	{
		printf(_CYAN "%Lf%%\tfor %s" _RESET, ((long double)tmp->t)/total, tmp->name);
		ft_puttab(tmp->name, 4);
		printf(_CYAN "in %Lf seconds\n" _RESET, ((long double)tmp->t));
		tmp = tmp->next;
	}
}

long double	cl(clock_t t)
{
	static long double	origin;
	long double m;

	if (!origin)
		origin = ((long double)(clock()));
	m = ((long double)(t - origin))/CLOCKS_PER_SEC;
	return (m);
	//origin = ((long double)(clock()))/CLOCKS_PER_SEC;
}

static t_time	*time_link_creation(const char* s, long double t)
{
	t_time	*timee;

	if(!(timee = (t_time*)malloc(sizeof(t_time))))
		return (NULL);
	timee->name = ft_strdup((const char*)s);
	timee->t = t;
	timee->next = NULL;
	print_time_struct(timee);
	return(timee);
}

static t_time	*time_exceptions( t_time *timee, const char* s, long double t)
{
	if (s == NULL)
		return (NULL);
	else
	{
		timee = time_link_creation(s, t);
		return (timee);
	}
}

static int		update_time( t_time *timee, const char* s, long double t)
{
	if (ft_strstr(s, timee->name))
	{
		timee->t = timee->t + t;
		return (1);
	}
	return (0);
}

t_time	*time_exe(const char* s, long double t)
{
	static t_time		*timee;
	t_time				*tmp;

	if (s == NULL || timee == NULL)
		return (time_exceptions(timee, s, t));
	tmp = timee;
	if (update_time(timee, s, t))
		return (timee);
	while (tmp->next != NULL)
	{
		if (update_time(timee, s, t))
			return (timee);
		tmp = tmp->next;
	}
	tmp->next = time_link_creation(s, t);
	return (timee);
}