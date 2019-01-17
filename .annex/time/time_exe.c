/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:52:19 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/17 15:06:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

/*
**	time_exe(__func__, clock());
**	print_time(time_exe(__func__, clock()));
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

t_time	*list_exchange(t_time **timee)
{
	t_time	*first;
	t_time	*middle;
	t_time	*last;

	if (*timee == NULL)
		return (NULL);
	first = (*timee);
	middle = (*timee)->next;
	last = (*timee)->next->next;

	(*timee) = middle;
	(*timee)->next = first;
	(*timee)->next->next = last;
	return (*timee);
}

void	sort_list(t_time **timee)
{
	t_time	*tmp;
	t_time	*late;

	tmp = *timee;
	late = NULL;
	while (tmp->next != NULL)
	{
		if (tmp->t > tmp->next->t && late != NULL)
		{
			list_exchange(&(late->next));
			tmp = *timee;
			late = NULL;
		}
		tmp = tmp->next;
		if (late == NULL)
			late = *timee;
		else
			late = late->next;
	}
}

void	print_elements(t_time *tmp, double total, int tab)
{
	printf("\t____________________________________________________________________\n");
	while (tmp)
	{
		if (total != 0)
		{
			printf("\t");
				if ((int)(((tmp->t)/total) * 100) / 10 < 1)
					printf(" ");
			printf(_YELLOW "%d%%" _RESET, (int)(((tmp->t)* 100/total) + 0.5));
		}
		else
			printf("\t");
		printf(_RED "\t%s" _RESET, tmp->name);
		ft_puttab(tmp->name, tab);
		printf(_MAGENTA "%f s\n" _RESET, ((double)tmp->t));
		printf(_GREEN "\t%dn" _RESET, tmp->nb_call);
		ft_puttab_nb(ft_intlen(tmp->nb_call), tab);
		printf(_CYAN "Rt:\t%f s/n\n" _RESET, (double)(tmp->t/tmp->nb_call));
		printf("\t____________________________________________________________________\n");
		tmp = tmp->next;
	}
}
void	print_total(double total)
{
	int			min;

	if (total <= 1)
		printf(_CYAN "\n\t\tProgram took " _GREEN "%f"
		_CYAN " seconds to execute\n\n" _RESET, (double)total);
	else if (total < 60)
		printf(_CYAN "\n\t\tProgram took " _YELLOW "%f"
		_CYAN " seconds to execute\n\n" _RESET, (double)total);
	else
	{
		min = (int)total/60;
		total = total - (min * 60);
		printf(_CYAN "\n\t\tProgram took\t" _RED "%d"
		_CYAN " minutes " _RED "\n\t\t\t\t%f" _CYAN " seconds to execute\n\n"
		_RESET, min, total);
	}
}

void	print_time(t_time *timee)
{
	t_time		*tmp;
	double		total;
	int			max_length;

	total = 0;
	tmp = timee;
	max_length = 0;
	while (tmp)
	{
		total += tmp->t;
		if (max_length < ft_strlen(tmp->name))
			max_length = (ft_strlen(tmp->name) / 4);
		tmp = tmp->next;
	}
	tmp = timee;
	if (!(timee = (t_time*)malloc(sizeof(t_time))))
		return ;
	timee->t = 0;
	timee->next = tmp;
	sort_list(&timee);
	print_elements(timee->next, total, max_length + 8);
	print_total(total);
}

double	cl(clock_t t)
{
	static double	last;
	double m;

	m = ((double)(t - last))/(CLOCKS_PER_SEC);
	last = ((double)(clock()));
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
	return(timee);
}

static t_time	*time_exceptions( t_time **timee, char **last, const char* s, double t)
{
	if (s == NULL)
	{
		cl(clock());
		return (NULL);
	}
	else
	{
		*last = ft_strdup((const char*)s);
		*timee = time_link_creation(s, t);
		cl(clock());
		return (*timee);
	}
}

static int		update_time(t_time *timee, const char* s, double t)
{
	if (!ft_strcmp(s, timee->name))
	{
		timee->t = timee->t + t;
		timee->nb_call++;
		return (1);
	}
	return (0);
}

t_time	*update_last(t_time *timee, char **last, const char* s)
{
	char* tmp;

	if (ft_strcmp(s, *last))
	{
		tmp = (char *)*last;
		*last = ft_strdup((const char*)s);
		free(tmp);
	}
	cl(clock());
	return (timee);
}

t_time	*time_exe(const char* s, double t)
{
	static t_time		*timee;
	static char			*last;
	t_time				*tmp;

	t = cl(t);
	if (s == NULL || timee == NULL || last == NULL)
		return (time_exceptions(&timee, &last, s, t));
	if (update_time(timee, (const char*)last, t))
		return (update_last(timee, &last, s));
	tmp = timee;
	while (tmp->next != NULL)
	{
		if (update_time(tmp, (const char*)last, t))
			return (update_last(timee, &last, s));
		tmp = tmp->next;
	}
	if (update_time(tmp, (const char*)last, t))
		return (update_last(timee, &last, s));
	tmp->next = time_link_creation((const char*)last, t);
	return (update_last(timee, &last, s));
}
