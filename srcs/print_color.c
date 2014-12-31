/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 13:55:03 by alegent           #+#    #+#             */
/*   Updated: 2014/12/31 12:31:58 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_color(char *str, t_stat *info)
{
	if (S_ISDIR(info->st_mode))
		putcolor(str, CYAN);
	else if (S_ISBLK(info->st_mode))
		putcolor(str, B_BLUE);
	else if (S_ISCHR(info->st_mode))
		putcolor(str, B_YELLOW);
	else if (S_ISLNK(info->st_mode))
		putcolor(str, PURPLE);
	else if (info->st_mode & S_IXUSR)
		putcolor(str, RED);
	else
		ft_putstr(str);
}
