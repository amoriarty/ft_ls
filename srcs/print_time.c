/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:14:09 by alegent           #+#    #+#             */
/*   Updated: 2015/01/06 12:04:05 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			is_early(time_t *clock, time_t *current)
{
	if ((*clock + 15778463) < *current)
		return (FALSE);
	if (*clock < *current)
		return (TRUE);
	return (FALSE);
}

void				print_time(t_stat *info)
{
	t_time			*new;
	time_t			current;

	new = get_time(&info->st_mtime);
	current = time(NULL);
	ft_putstr(new->month);
	ft_putchar(' ');
	ft_putstr(new->day);
	ft_putchar(' ');
	if (is_early(&info->st_mtime, &current))
	{
		ft_putstr(new->hour);
		ft_putchar(':');
		ft_putstr(new->minute);
	}
	else
	{
		ft_putchar(' ');
		ft_putstr(new->years);
	}
	ft_putchar(' ');
}
