/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:31:44 by alegent           #+#    #+#             */
/*   Updated: 2014/12/31 13:17:51 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			to_print(t_node *list, char *name, char *path, t_stat *info)
{
	t_len			*len;

	len = len_calcul(list);
	print_perm(info->st_mode);
	calibration(len->nlink - ft_digitlen(info->st_nlink));
	ft_putnbr(info->st_nlink);
	ft_putchar(' ');
	print_usr(info, len);
	calibration(len->lsize - ft_digitlen(info->st_size));
	ft_putnbr(info->st_size);
	ft_putchar(' ');
	print_time(info);
	print_color(name, info);
	if (S_ISLNK(info->st_mode))
		print_link(ft_strjoin(path, name));
	ft_putchar(EOL);
}

void				print_long(t_node *list, t_opt *opt)
{
	t_node			*tmp;

	tmp = list;
	while (tmp)
	{
		if (opt->a == FALSE)
		{
			if (is_hidden(tmp->name) == FALSE)
				to_print(list, tmp->name, tmp->path, tmp->info);
		}
		else
			to_print(list, tmp->name, tmp->path, tmp->info);
		tmp = tmp->next;
	}
}
