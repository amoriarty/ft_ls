/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 14:42:23 by alegent           #+#    #+#             */
/*   Updated: 2014/12/05 19:04:02 by alegent          ###   ########.fr       */
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

static void			path_print(char *path, t_opt *option)
{
	static int		i;

	if (search(path) == TRUE)
		path[ft_strlen(path) - 1] = '\0';
	if (i++ > 0 && option->m_path == FALSE)
	{
		ft_putchar(EOL);
		ft_putstr(path);
		ft_putendl(":");
	}
	else if (option->m_path == TRUE)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	if (search(path) == FALSE)
		path[ft_strlen(path)] = '/';
}

static void			recursive(t_dlist *list, t_opt *option, char *path)
{
	t_entry			*tmp;

	tmp = list->begin;
	while (tmp != NULL)
	{
		if (S_ISDIR(tmp->info->st_mode)
				&& ft_strcmp(tmp->name, ".") != 0
				&& ft_strcmp(tmp->name, "..") != 0)
			lecture(ft_strjoin(path, tmp->name), option);
		tmp = tmp->next;
	}
}

int					lecture(char *path, t_opt *option)
{
	DIR				*my_dir;
	t_dirent		*my_dirent;
	t_dlist			*list;

	list = new_list();
	if (search(path) == FALSE)
		path = ft_strjoin(path, "/");
	if ((my_dir = opendir(path)) == NULL)
		return (ERROR);
	while ((my_dirent = readdir(my_dir)))
		list = append(list, my_dirent->d_name, path);
	closedir(my_dir);
	if (option->opt_l)
	{
		path_print(path, option);
		print_total(list);
	}
	print(list, option);
	if (option->opt_rec == TRUE)
		recursive(list, option, path);
	return (TRUE);
}
