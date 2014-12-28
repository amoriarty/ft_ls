/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 13:55:03 by alegent           #+#    #+#             */
/*   Updated: 2014/12/28 15:03:55 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_color(char *str, mode_t info)
{
	if (S_ISDIR(info))
		putcolor(str, CYAN);
	else if (S_ISBLK(info))
		putcolor(str, B_BLUE);
	else if (S_ISCHR(info))
		putcolor(str, B_YELLOW);
	else if (S_ISLNK(info))
		putcolor(str, PURPLE);
	else if (info & S_IXUSR)
		putcolor(str, RED);
	else
		ft_putendl(str);
}
