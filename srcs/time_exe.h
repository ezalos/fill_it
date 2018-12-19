/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:51:05 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/20 00:18:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_EXE_H
# define TIME_EXE_H

# include <head.h>

typedef struct	s_time
{
	clock_t		t;
	double		percent;
	char		*name;
	t_time		*next;
}				t_time;

#endif
