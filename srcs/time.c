/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 11:40:22 by alegent           #+#    #+#             */
/*   Updated: 2014/12/09 11:13:30 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_time				*init_time(t_time **my_time)
{
	*my_time = (t_time *)malloc(sizeof(t_time));
	(*my_time)->complet = NULL;
	(*my_time)->month = NULL;
	(*my_time)->day = NULL;
	(*my_time)->hour = NULL;
	(*my_time)->minute = NULL;
	(*my_time)->second = NULL;
	(*my_time)->year = NULL;
	return (*my_time);
}

t_time				*time_info(time_t *clock, t_time **my_time)
{
	*my_time = init_time(my_time);
	(*my_time)->complet = ctime(clock);
	(*my_time)->month = ft_strsub((*my_time)->complet, 4, 3);
	(*my_time)->day = ft_strsub((*my_time)->complet, 8, 2);
	(*my_time)->hour = ft_strsub((*my_time)->complet, 11, 2);
	(*my_time)->minute = ft_strsub((*my_time)->complet, 14, 2);
	(*my_time)->year = ft_strsub((*my_time)->complet, 20, 4);
	return (*my_time);
}

int					is_early(time_t *clock, time_t *current)
{
	if ((*clock + 15778463) < *current)
		return (FALSE);
	if (*clock < *current)
		return (TRUE);
	return (FALSE);
}
