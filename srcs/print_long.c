/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:31:44 by alegent           #+#    #+#             */
/*   Updated: 2015/01/13 10:53:11 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			to_print(t_node *list, t_node *tmp, t_opt *opt)
{
	t_len			*len;

	len = len_calcul(list, opt);
	print_perm(tmp->info->st_mode);
	calibration(len->nlink - ft_digitlen(tmp->info->st_nlink));
	ft_putnbr(tmp->info->st_nlink);
	ft_putchar(' ');
	print_usr(tmp->info, len);
	if (ft_strcmp(tmp->path, "/dev/") == 0)
		print_major(tmp->info, len);
	else
	{
		calibration(len->lsize - ft_digitlen(tmp->info->st_size));
		ft_putnbr(tmp->info->st_size);
	}
	ft_putchar(' ');
	print_time(tmp->info);
	print_color(tmp->name, tmp->info);
	if (S_ISLNK(tmp->info->st_mode))
		print_link(ft_strjoin(tmp->path, tmp->name));
	ft_putchar(EOL);
}

void				print_long(t_node *list, t_opt *opt)
{
	t_node			*tmp;
	t_stat			info;

	tmp = list;
	lstat(list->name, &info);
	if (!S_ISREG(info.st_mode))
		print_total(list);
	while (tmp)
	{
		if (opt->a == FALSE)
		{
			if (is_hidden(tmp->name) == FALSE || S_ISREG(info.st_mode))
				to_print(list, tmp, opt);
		}
		else
			to_print(list, tmp, opt);
		tmp = tmp->next;
	}
}
