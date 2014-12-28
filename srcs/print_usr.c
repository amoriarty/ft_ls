/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:05:51 by alegent           #+#    #+#             */
/*   Updated: 2014/12/18 15:31:24 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_usr(t_stat *info, t_len *len)
{
	t_passwd		*p_passwd;
	t_group			*p_grp;

	p_passwd = getpwuid(info->st_uid);
	p_grp = getgrgid(info->st_gid);
	if (p_passwd != NULL)
	{
		ft_putstr(p_passwd->pw_name);
		calibration(len->usr - ft_strlen(p_passwd->pw_name));
	}
	else
	{
		ft_putnbr(info->st_uid);
		calibration(len->usr - ft_digitlen(info->st_uid));
	}
	if (p_grp != NULL)
	{
		ft_putstr(p_grp->gr_name);
		calibration(len->grp - ft_strlen(p_grp->gr_name));
	}
	else
	{
		ft_putnbr(info->st_gid);
		calibration(len->grp - ft_digitlen(info->st_gid));
	}
}
