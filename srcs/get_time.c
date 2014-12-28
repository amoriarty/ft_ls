/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:07:23 by alegent           #+#    #+#             */
/*   Updated: 2014/12/17 16:21:02 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_time				*get_time(time_t *clock)
{
	t_time			*new;

	new = init_time();
	new->complet = ctime(clock);
	new->month = ft_strsub(new->complet, 4, 3);
	new->day = ft_strsub(new->complet, 8, 2);
	new->hour = ft_strsub(new->complet, 11, 2);
	new->minute = ft_strsub(new->complet, 14, 2);
	new->years = ft_strsub(new->complet, 20, 4);
	return (new);
}
