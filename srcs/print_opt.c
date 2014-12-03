/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 10:22:58 by alegent           #+#    #+#             */
/*   Updated: 2014/12/03 10:26:58 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
void				print_l(t_dlist *list, t_opt *option)
{
	if (option->opt_l == TRUE)
	{
		if (option->opt_a == FALSE)
		{
			if (is_hidden(my_entry->name) == FALSE)
				print_long(list);
		}
		else
			print_long(list);
	}
}

void				print_rec(t_entry *my_entry, t_stat *info, t_opt *option)
{
	t_entry			*tmp;

	tmp = my_entry;
	while (tmp != NULL)
	{
		if (option->opt_l == TRUE)
			print_l(my_entry, info, option);
		else if (option->opt_a == FALSE)
		{
			if (is_hidden(my_entry->name) == FALSE)
				ft_putendl(my_entry->name);
		}
		else
			ft_putendl(my_entry->name);
		if (S_ISDIR(info->st_mode)
				&& ft_strcmp(my_entry->name, ".") != 0
				&& ft_strcmp(my_entry->name, "..") != 0)
			lecture(my_entry->name, option);
		tmp = tmp->next;
	}
}
*/
