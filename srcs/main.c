/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:56:30 by alegent           #+#    #+#             */
/*   Updated: 2014/11/28 12:38:50 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "libft.h"
#include "ft_ls.h"
#include "struct.h"

int					main(int ac, char **av)
{
	DIR				*my_dir;
	t_dirent		*my_dirent;
	t_stat			my_stat;
	t_time			*my_time;

	my_dir = NULL;
	my_dirent = NULL;
	my_time = NULL;
	if (ac > 1)
	{
		if ((my_dir = opendir(av[1])) == NULL)
			return (ERROR);
		while ((my_dirent = readdir(my_dir)))
		{
			stat(my_dirent->d_name, &my_stat);
			time_info(&my_stat.st_mtime, my_time);
			ft_putendl(my_time->month);
			ft_putendl(my_time->day);
			ft_putstr(my_time->hour);
			ft_putchar(':');
			ft_putendl(my_time->minute);
		}
	}
	return (42);
}
