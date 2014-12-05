/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 18:56:11 by alegent           #+#    #+#             */
/*   Updated: 2014/12/05 19:14:24 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print(t_dlist *list, t_opt *option)
{
	t_entry			*tmp;

	tmp = (option->opt_r == TRUE) ? list->end : list->begin;
	while (tmp)
	{
		if (option->opt_a)
		{
			if (option->opt_l)
				print_long(tmp, list);
			else
				ft_putendl(tmp->name);
		}
		else if (is_hidden(tmp->name) == FALSE)
		{
			if (option->opt_l)
				print_long(tmp, list);
			else
				ft_putendl(tmp->name);
		}
		tmp = (option->opt_r == TRUE) ? tmp->prec : tmp->next;
	}
}
