/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:52:19 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/23 02:43:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

/*
time_exe(__func__, cl(clock()));
print_time(time_exe(__func__, clock()));
*/

void 	print_time_struct(t_time *g)
{
	printf(_RED"\t\tAdress:\t\t%p\n", (void *)g);
	printf(_CYAN "\t%s" _RESET, g->name);
	ft_puttab(g->name, 4);
	printf(_CYAN "Time: %f s.\n" _RESET, ((double)g->t));
 	printf("\t\tNEXT:\t\t%p\n\n" _RESET, (void*)g->next);
}

void	ft_puttab_nb(int length, int separation)
{
	int n = 4; //is equal to 8 for windows
	int tab = 0;
	while (tab + length < separation * n)
	{
		printf(" ");
		tab++;
	}
}

void	ft_puttab(const char *s, int separation)
{
	int n = 4; //is equal to 8 for windows
	int tab = 0;
	int length = ft_strlen(s);
	int bb = 0;

	while (tab + length < separation * n)
	{
		printf(" ");
		tab++;
	}
}

void	print_time(t_time *timee)
{
	t_time		*tmp;
	double		total;
	int			max_length = 0;
	int			tab = 6;

	total = 0;
	tmp = timee;
	while (tmp)
	{
		total += (double)tmp->t;
		if (max_length < ft_strlen(tmp->name))
			max_length = (ft_strlen(tmp->name) / 4);
		tmp = tmp->next;
	}
	printf(_CYAN "\nTotal time of program: %f\n\n" _RESET, (double)total);

	tab = max_length + 4;
	tmp = timee;
	printf("\t________________________________________________________\n");
	while (tmp)
	{
		if (total != 0)
		{
			printf("\t");
				if ((int)(((tmp->t)/total) * 100) / 10 < 1)
					printf(" ");
			printf(_YELLOW "%d%%" _RESET, (int)(((tmp->t)/total) * 100));
		}
		else
			printf("\t");
		printf(_RED "\t%s" _RESET, tmp->name);
		ft_puttab(tmp->name, tab);
		printf(_MAGENTA "%f s\n" _RESET, ((double)tmp->t));
		printf(_GREEN "\t%dn" _RESET, tmp->nb_call);
		ft_puttab_nb(ft_intlen(tmp->nb_call), tab);
		printf(_CYAN "Rt:\t%f s/n\n" _RESET, (double)(tmp->t/tmp->nb_call));
		printf("\t________________________________________________________\n");
		tmp = tmp->next;
	}
}

double	cl(clock_t t)
{
	static double	origin;
	double m;

	if (!origin)
		origin = ((double)(clock()));
	m = ((double)(t - origin))/(CLOCKS_PER_SEC);
	return (m);
}

static t_time	*time_link_creation(const char* s, double t)
{
	t_time	*timee;

	if(!(timee = (t_time*)malloc(sizeof(t_time))))
		return (NULL);
	timee->name = ft_strdup((const char*)s);
	timee->t = t;
	timee->nb_call = 1;
	timee->next = NULL;
//	print_time_struct(timee);
	return(timee);
}

static t_time	*time_exceptions( t_time **timee, const char* s, double t)
{
	if (s == NULL)
		return (NULL);
	else
	{
		*timee = time_link_creation(s, t);
		return (*timee);
	}
}

static int		update_time( t_time *timee, const char* s, double t)
{
	if (!ft_strcmp(s, timee->name))
	{
		timee->t = timee->t + t;
		timee->nb_call++;
		return (1);
	}
	return (0);
}

t_time	*time_exe(const char* s, double t)
{
	static t_time		*timee;
	t_time				*tmp;

	if (s == NULL || timee == NULL)
		return (time_exceptions(&timee, s, t));
	if (update_time(timee, s, t))
		return (timee);
	tmp = timee;
	while (tmp->next != NULL)
	{
		if (update_time(tmp, s, t))
			return (timee);
		tmp = tmp->next;
	}
	if (update_time(tmp, s, t))
		return (timee);
	tmp->next = time_link_creation(s, t);
	return (timee);
}
