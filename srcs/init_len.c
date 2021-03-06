/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:19:21 by alegent           #+#    #+#             */
/*   Updated: 2014/12/31 15:28:37 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_len				*init_len(void)
{
	t_len			*new;

	if ((new = (t_len *)malloc(sizeof(t_len))) == NULL)
		return (NULL);
	new->nlink = 0;
	new->lsize = 0;
	new->usr = 0;
	new->grp = 0;
	new->lmajor = 0;
	new->lminor = 0;
	return (new);
}
