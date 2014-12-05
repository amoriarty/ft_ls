/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 14:42:23 by alegent           #+#    #+#             */
/*   Updated: 2014/12/05 15:20:19 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			search(char *path)
{
	int				i;

	i = 0;
	while (path[i])
		i++;
	if (path[i - 1] == '/')
		return (TRUE);
	return (FALSE);
}

int					lecture(char *path, t_opt *option)
{
	DIR				*my_dir;
	t_dirent		*my_dirent;
	t_dlist			*list;
	t_entry			*tmp;

	list = new_list();
	if (search(path) == FALSE)
		path = ft_strjoin(path, "/");
	if ((my_dir = opendir(path)) == NULL)
		return (ERROR);
	while ((my_dirent = readdir(my_dir)))
		list = append(list, my_dirent->d_name, path);
	closedir(my_dir);
	ft_putendl(path);
	print_long(list);
	tmp = list->begin;
	while (tmp != NULL && option != NULL)
	{
		if (option->opt_rec == TRUE && S_ISDIR(tmp->info->st_mode)
				&& ft_strcmp(tmp->name, ".") != 0
				&& ft_strcmp(tmp->name, "..") != 0)
			lecture(ft_strjoin(path, tmp->name), option);
		tmp = tmp->next;
	}
	return (TRUE);
}
