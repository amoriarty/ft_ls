/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 10:05:19 by alegent           #+#    #+#             */
/*   Updated: 2015/01/04 15:17:49 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			recursive(t_node *list, t_opt *opt, char *dir_name)
{
	t_node			*tmp;

	tmp = list;
	while (tmp)
	{
		if (S_ISDIR(tmp->info->st_mode) && current_dir(tmp->name) == FALSE)
		{
			if (is_complet(dir_name) == FALSE)
				dir_name = ft_strjoin(dir_name, "/");
			ft_putchar(EOL);
			ft_putstr(ft_strjoin(dir_name, tmp->name));
			ft_putendl(": ");
			reading(opt, ft_strjoin(dir_name, tmp->name));
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int					reading(t_opt *opt, char *dir_name)
{
	DIR				*p_dir;
	t_dirent		*p_dirent;
	t_node			*list;

	list = NULL;
	if ((p_dir = opendir(dir_name)))
	{
		while ((p_dirent = readdir(p_dir)))
			list = insert_node(list, p_dirent->d_name, dir_name, opt);
		closedir(p_dir);
//		list = sort_ascii(list);
		print(list, opt);
		if (opt->rec)
			recursive(list, opt, dir_name);
		return (SUCCESS);
	}
	ft_putstr("ft_ls: ");
	ft_putstr(dir_name);
	ft_putstr(": ");
	perror("");
	return (FAILURE);
}
