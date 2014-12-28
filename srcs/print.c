/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 10:54:02 by alegent           #+#    #+#             */
/*   Updated: 2014/12/28 15:08:57 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print(t_node *list, t_opt *opt)
{
	t_node			*tmp;

	tmp = list;
	if (opt->l == TRUE)
		print_long(list, opt);
	else
	{
		while (tmp)
		{
			if (opt->a == FALSE)
			{
				if (is_hidden(tmp->name) == FALSE)
					print_color(tmp->name, tmp->info->st_mode);
			}
			else
				print_color(tmp->name, tmp->info->st_mode);
			tmp = tmp->next;
		}
	}
}
