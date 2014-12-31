/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 10:54:02 by alegent           #+#    #+#             */
/*   Updated: 2014/12/31 12:33:56 by alegent          ###   ########.fr       */
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
				{
					print_color(tmp->name, tmp->info);
					ft_putchar(EOL);
				}
			}
			else
			{
				print_color(tmp->name, tmp->info);
				ft_putchar(EOL);
			}
			tmp = tmp->next;
		}
	}
}
