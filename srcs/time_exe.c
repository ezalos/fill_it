/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:52:19 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/20 13:07:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

/*

	time_exe("NAME OF PROGRAM", clock())


time_exe(__func__, clock());

print_time(time_exe(__func__, clock()));

	clock_t	t = clock();
 */


void print_time_struct(t_time *g)
{
	printf(_RED"\tAdress:\t\t%p\n", (void *)g);
 	printf("\tNAME:\t\t%s\t\tTime:%Lf\n", g->name, g->t);
 	printf("\tNEXT:\t\t%p\n" _RESET, (void*)g->next);
}


void	print_time(t_time *timee)
{
	t_time		*tmp;
	long double		total;

	total = 0;
	tmp = timee;
	while (tmp)
	{
		total += (long double)tmp->t;
		tmp = tmp->next;
	}
	printf(_CYAN "Total: %Lf\n" _RESET, (long double)total);

	tmp = timee;
	while (tmp)
	{
		printf(_CYAN "%Lf%%\t%s\n\t\t\ttook %Lf seconds to execute \n" _RESET, ((long double)tmp->t)/total, tmp->name, ((long double)tmp->t));
		tmp = tmp->next;
	}
}

long double	cl(clock_t t)
{
	static long double	origin;
	long double m;

	if (!origin)
		origin = ((long double)(clock()))/CLOCKS_PER_SEC;
	m = ((long double)(t - origin))/CLOCKS_PER_SEC;
	return (m);
}

t_time	*time_link_creation(const char* s, long double t)
{
	t_time	*timee;

	if(!(timee = (t_time*)malloc(sizeof(t_time))))
		return (NULL);
	timee->name = ft_strdup((const char*)s);
//	printf("t:%LF\ntimee->t:%LF",t ,timee->t);
	timee->t = t;
	printf("t:%LF\ntimee->t:%LF\n",t ,timee->t);
	timee->next = NULL;
	print_time_struct(timee);
	return(timee);
}

t_time	*time_exe(const char* s, long double t)
{
	static t_time		*timee;
	t_time				*tmp;
	static long double	latest;

	//write(1, "@", 1);
	printf(_CYAN"NAME :__func__ :%s\t\tpointer :%p\ntime :%Lf\n\n\t\tLatest:%Lf\n", s, (void*)timee, t, latest);
	if (s == NULL)
	{
		latest = t;
		return (NULL);
	}
	if (timee == NULL)
	{
		printf("\t\tFirst link created for : %s\n", s);
		timee = time_link_creation(s, t);
		latest = t;
		return (timee);
	}
	tmp = timee;
	if (ft_strstr(s, tmp->name))
	{
		printf("YES!\n");
		tmp->t = tmp->t + t;
		printf("t:%LF\ntmp->t:%LF\n",t ,tmp->t);
		latest = t;
		return (timee);
	}
	while (tmp->next != NULL)
//	while (tmp)
	{
		printf("\t\tDoes %s could be stored in %s ?\n", s, tmp->name);
		print_time_struct(tmp);
		if (ft_strstr(s, tmp->name))
		{
			printf("YES!\n");
			tmp->t = tmp->t + t;
			printf("t:%LF\ntmp->t:%LF\n",t ,tmp->t);
			latest = t;
			return (timee);
		}
		tmp = tmp->next;
	}
	printf("\tNop, let's create a new one\n");
	tmp->next = time_link_creation(s, t);
	latest = t;
	printf("\tEnd\n" _RESET);
	printf("\tPointer TIMEE:%p\n"_RESET, (void *)timee);
	return (timee);
}
