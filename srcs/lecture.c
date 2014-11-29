/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 09:20:11 by alegent           #+#    #+#             */
/*   Updated: 2014/11/29 10:10:31 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "libft.h"
#include "ft_ls.h"
#include "struct.h"

int					lecture(char *dir_name, t_opt *option)
{
	DIR				*my_dir;
	t_dirent		*my_dirent;
	t_stat			my_stat;

	my_dir = NULL;
	my_dirent = NULL;
	if ((my_dir = opendir(dir_name)) == NULL)
		return (ERROR);
	while ((my_dirent = readdir(my_dir)))
	{
		stat(my_dirent->d_name, &my_stat);
		if ((S_ISDIR(my_stat.st_mode)) && (option->opt_rec == TRUE)
				&& ft_strcmp(my_dirent->d_name, ".") != 0
				&& ft_strcmp(my_dirent->d_name, "..") != 0)
			lecture(my_dirent->d_name, option);
		if ((ft_strcmp(my_dirent->d_name, ".") != 0)
				&& (ft_strcmp(my_dirent->d_name, "..") != 0)
				&& (option->opt_l == TRUE))
			print_global(&my_stat, my_dirent->d_name);
		else if ((ft_strcmp(my_dirent->d_name, ".") != 0)
				&& (ft_strcmp(my_dirent->d_name, "..") != 0))
			ft_putendl(my_dirent->d_name);
	}
	return (TRUE);
}
