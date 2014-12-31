/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:24:24 by alegent           #+#    #+#             */
/*   Updated: 2014/12/31 15:21:33 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t		usr(t_stat *info)
{
	t_passwd		*p_passwd;

	if ((p_passwd = getpwuid(info->st_uid)))
		return (ft_strlen(p_passwd->pw_name));
	else
		return (ft_digitlen(info->st_uid));
}

static size_t		grp(t_stat *info)
{
	t_group			*p_grp;

	if ((p_grp = getgrgid(info->st_gid)))
		return (ft_strlen(p_grp->gr_name));
	else
		return (ft_digitlen(info->st_gid));
}

t_len				*len_calcul(t_node *list)
{
	t_node			*tmp;
	t_len			*new;

	tmp = list;
	new = init_len();
	while (tmp)
	{
		new->nlink = (new->nlink < ft_digitlen(tmp->info->st_nlink))
			? ft_digitlen(tmp->info->st_nlink) : new->nlink;
		new->lsize = (new->lsize < ft_digitlen(tmp->info->st_size))
			? ft_digitlen(tmp->info->st_size) : new->lsize;
		new->usr = (new->usr < usr(tmp->info))
			? usr(tmp->info) : new->usr;
		new->grp = (new->grp < grp(tmp->info))
			? grp(tmp->info) : new->grp;
		new->lmajor = (new->lmajor < ft_digitlen(major(tmp->info->st_rdev)))
			? ft_digitlen(major(tmp->info->st_rdev)) : new->lmajor;
		new->lminor = (new->lminor < ft_digitlen(minor(tmp->info->st_rdev)))
			? ft_digitlen(minor(tmp->info->st_rdev)) : new->lminor;
		tmp = tmp->next;
	}
	return (new);
}
