/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:05:51 by alegent           #+#    #+#             */
/*   Updated: 2015/01/06 14:49:25 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			strname(char *str, size_t len)
{
	ft_putstr(str);
	calibration(len - ft_strlen(str));
}

void				print_usr(t_stat *info, t_len *len)
{
	t_passwd		*p_passwd;
	t_group			*p_grp;

	p_passwd = getpwuid(info->st_uid);
	p_grp = getgrgid(info->st_gid);
	if (p_passwd != NULL)
		strname(p_passwd->pw_name, len->usr);
	else
	{
		ft_putnbr(info->st_uid);
		calibration(len->usr - ft_digitlen(info->st_uid));
	}
	ft_putchar(' ');
	if (p_grp != NULL)
		strname(p_grp->gr_name, len->grp);
	else
	{
		ft_putnbr(info->st_gid);
		calibration(len->grp - ft_digitlen(info->st_gid));
	}
}
