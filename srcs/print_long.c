/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 11:18:11 by alegent           #+#    #+#             */
/*   Updated: 2014/12/02 15:56:56 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void				print_usr(uid_t usr, gid_t gr)
{
	t_passwd		*my_passwd;
	t_group			*my_grp;

	my_passwd = getpwuid(usr);
	my_grp = getgrgid(gr);
	ft_putstr(my_passwd->pw_name);
	ft_putchar(' ');
	ft_putstr(my_grp->gr_name);
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

void				print_global(t_stat *info, char *name)
{
	t_time			*my_time;

	my_time = NULL;
	print_perm(info->st_mode);
	ft_putnbr(info->st_nlink);
	ft_putchar(' ');
	print_usr(info->st_uid, info->st_gid);
	ft_putnbr(info->st_size);
	ft_putchar(' ');
	my_time = time_info(&info->st_mtime, &my_time);
	print_time(my_time);
	ft_putendl(name);
}
