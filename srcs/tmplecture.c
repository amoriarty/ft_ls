/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 09:20:11 by alegent           #+#    #+#             */
/*   Updated: 2014/12/03 17:11:19 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*manage_path(char *dir_name)
{
	static char		*path;

	if (path == NULL)
	{
		path = ft_strdup(dir_name);
		return (path);
	}
	path = ft_strjoin(path, "/");
	path = ft_strjoin(path, dir_name);
	return (path);
}

static void			recursive(t_dlist *list, t_opt *option)
{
	t_entry			*tmp;

	tmp = list->begin;
	ft_putchar(EOL);
	while (tmp != NULL)
	{
		if ((S_ISDIR(tmp->info->st_mode)) == TRUE
				&& ft_strcmp(tmp->name, ".") != 0
				&& ft_strcmp(tmp->name, "..") != 0)
			lecture(tmp->name, option);
		tmp = tmp->next;
	}
}

int					lecture(char *dir_name, t_opt *option)
{
	DIR				*my_dir;
	t_dirent		*my_dirent;
	t_dlist			*list;
	char			*path;
	static size_t	i;

	my_dir = NULL;
	my_dirent = NULL;
	list = new_list();
	path = manage_path(dir_name);
	if ((my_dir = opendir(dir_name)) == NULL)
		return (ERROR);
	while ((my_dirent = readdir(my_dir)))
		list = append(list, my_dirent->d_name);
	closedir(my_dir);
	if (i++ > 0)
		ft_putendl(path);
	print_long(list);
	if (option == NULL)
		return (TRUE);
	else if (option->opt_rec == TRUE)
		recursive(list, option);
	return (TRUE);
}
