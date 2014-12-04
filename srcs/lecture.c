/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 14:42:23 by alegent           #+#    #+#             */
/*   Updated: 2014/12/04 16:16:04 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			search(char *path)
{
	int				i;

	i = 0;
	while (path[i++]);
	if (path[i - 1] == '/')
		return (TRUE);
	return (FALSE);
}

static char			*manage_path(char *path, char *dir_name)
{
	char			*new_path;

	new_path = NULL;
	if (search(path) == FALSE)
		new_path = ft_strjoin(path, "/");
	new_path = ft_strjoin(new_path, dir_name);
	return (new_path);
}

/*
static char			*manage_file(char *path, char *file)
{
	char			*new_file;

	new_file = NULL;
	if (ft_strchr(path, '/') == NULL)
		new_file = ft_strjoin(path, "/");
	new_file = ft_strjoin(new_file, file);
	return (new_file);
}
*/

int					lecture(char *path, t_opt *option)
{
	DIR				*my_dir;
	t_dirent		*my_dirent;
	t_dlist			*list;
	t_entry			*tmp;

	list = new_list();
	if ((my_dir = opendir(path)) == NULL)
		return (ERROR);
	while ((my_dirent = readdir(my_dir)))
			list = append(list, my_dirent->d_name);
	closedir(my_dir);
	ft_putendl(path);
	print_long(list);
	tmp = list->begin;
	while (tmp != NULL)
	{
		if (option->opt_rec == TRUE && S_ISDIR(tmp->info->st_mode)
				&& ft_strcmp(tmp->name, ".") != 0
				&& ft_strcmp(tmp->name, "..") != 0)
		{
			path = manage_path(path, tmp->name);
			lecture(path, option);
		}
		tmp = tmp->next;
	}
	return (TRUE);
}
