/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:04:24 by alegent           #+#    #+#             */
/*   Updated: 2014/12/17 16:39:37 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_time				*init_time(void)
{
	t_time			*new;

	if ((new = (t_time *)malloc(sizeof(t_time))) == NULL)
		return (NULL);
	new->complet = NULL;
	new->month = NULL;
	new->day = NULL;
	new->hour = NULL;
	new->minute = NULL;
	new->second = NULL;
	new->years = NULL;
	return (new);
}
