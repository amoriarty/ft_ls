/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 09:20:11 by alegent           #+#    #+#             */
/*   Updated: 2014/12/02 15:57:17 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					lecture(char *dir_name, t_opt *option)
{
	DIR				*my_dir;
	t_dirent		*my_dirent;
	t_dlist			*list;
	t_entry			*tmp;

	my_dir = NULL;
	my_dirent = NULL;
	list = new_list();
	if ((my_dir = opendir(dir_name)) == NULL)
		return (ERROR);
	while ((my_dirent = readdir(my_dir)) && (option != NULL))
		list = append(list, my_dirent->d_name);
	closedir(my_dir);
	tmp = list->begin;
	while (tmp != NULL)
	{
		print_global(tmp->info, tmp->name);
		tmp = tmp->next;
	}
	return (TRUE);
}
