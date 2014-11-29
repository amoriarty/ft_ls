/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 09:20:11 by alegent           #+#    #+#             */
/*   Updated: 2014/11/29 15:32:57 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "libft.h"
#include "ft_ls.h"
#include "struct.h"

static t_entry		*tri(char *name, t_stat *info, t_entry *begin)
{
	t_entry			*new;
	t_entry			*tmp;

	if ((new = (t_entry *)malloc(sizeof(t_entry))) == NULL)
		return (NULL);
	new->name = ft_strdup(name);
	new->info = info;
	if (begin == NULL)
	{
		new->next = NULL;
		return (new);
	}
	tmp = begin;
	while ((ft_strcmp(name, tmp->name) <= 0) && (tmp->next != NULL))
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
	free(tmp);
	return (new);
}

int					lecture(char *dir_name, t_opt *option)
{
	DIR				*my_dir;
	t_dirent		*my_dirent;
	t_stat			my_stat;
	t_entry			*my_entry;
	t_entry			*tmp;

	my_dir = NULL;
	my_dirent = NULL;
	my_entry = NULL;
	if ((my_dir = opendir(dir_name)) == NULL)
		return (ERROR);
	while ((my_dirent = readdir(my_dir)) && (option != NULL))
	{
		stat(my_dirent->d_name, &my_stat);
		/*
		if ((S_ISDIR(my_stat.st_mode)) && (option->opt_rec == TRUE)
				&& ft_strcmp(my_dirent->d_name, ".") != 0
				&& ft_strcmp(my_dirent->d_name, "..") != 0)
			lecture(my_dirent->name, option);
		if ((ft_strcmp(my_dirent->d_name, ".") != 0)
				&& (ft_strcmp(my_dirent->d_name, "..") != 0)
				&& (option->opt_l == TRUE))
			print_global(&my_stat, my_dirent->d_name);
		else if ((ft_strcmp(my_dirent->d_name, ".") != 0)
				&& (ft_strcmp(my_dirent->d_name, "..") != 0))
			ft_putendl(my_dirent->d_name);
			*/
		my_entry = tri(my_dirent->d_name, &my_stat, my_entry);
		tmp = my_entry;
		while (tmp != NULL)
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
		free(tmp);
	}
	closedir(my_dir);
	return (TRUE);
}
