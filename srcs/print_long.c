/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 11:18:11 by alegent           #+#    #+#             */
/*   Updated: 2014/12/03 15:03:33 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			recalibrage(size_t max)
{
	size_t			len;

	len = 0;
	while (len++ < max)
		ft_putchar(' ');
}

void				print_perm(mode_t info)
{
	ft_putchar((S_ISDIR(info)) ? 'd' : '-');
	ft_putchar((info & S_IRUSR) ? 'r' : '-');
	ft_putchar((info & S_IWUSR) ? 'w' : '-');
	ft_putchar((info & S_IXUSR) ? 'x' : '-');
	ft_putchar((info & S_IRGRP) ? 'r' : '-');
	ft_putchar((info & S_IWGRP) ? 'w' : '-');
	ft_putchar((info & S_IXGRP) ? 'x' : '-');
	ft_putchar((info & S_IROTH) ? 'r' : '-');
	ft_putchar((info & S_IWOTH) ? 'w' : '-');
	ft_putchar((info & S_IXOTH) ? 'x' : '-');
	ft_putchar (' ');
}

void				print_usr(uid_t usr, gid_t gr, t_dlist *list)
{
	t_passwd		*my_passwd;
	t_group			*my_grp;

	my_passwd = getpwuid(usr);
	my_grp = getgrgid(gr);
	ft_putstr(my_passwd->pw_name);
	recalibrage(len_usr(list) - ft_strlen(my_passwd->pw_name));
	ft_putchar(' ');
	ft_putstr(my_grp->gr_name);
	recalibrage(len_grp(list) - ft_strlen(my_grp->gr_name));
	ft_putchar(' ');
}

void				print_time(t_time *info)
{
	ft_putstr(info->month);
	ft_putchar(' ');
	ft_putstr(info->day);
	ft_putchar(' ');
	ft_putstr(info->hour);
	ft_putchar(':');
	ft_putstr(info->minute);
	ft_putchar(' ');
}

void				print_long(t_dlist *list)
{
	t_entry			*tmp;
	t_time			*my_time;

	my_time = NULL;
	tmp = list->begin;
	print_total(list);
	while (tmp != NULL)
	{
		print_perm(tmp->info->st_mode);
		recalibrage(len_nlink(list) - digitlen(tmp->info->st_nlink));
		ft_putnbr(tmp->info->st_nlink);
		ft_putchar(' ');
		print_usr(tmp->info->st_uid, tmp->info->st_gid, list);
		recalibrage(len_size(list) - digitlen(tmp->info->st_size));
		ft_putnbr(tmp->info->st_size);
		ft_putchar(' ');
		my_time = time_info(&tmp->info->st_mtime, &my_time);
		print_time(my_time);
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}
