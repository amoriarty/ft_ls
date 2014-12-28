/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:51:09 by alegent           #+#    #+#             */
/*   Updated: 2014/12/28 14:35:44 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			file_type(mode_t info)
{
	if (S_ISDIR(info))
		ft_putchar('d');
	else if (S_ISLNK(info))
		ft_putchar('l');
	else if (S_ISBLK(info))
		ft_putchar('b');
	else if (S_ISCHR(info))
		ft_putchar('c');
	else if (S_ISREG(info))
		ft_putchar('-');
}

void				print_perm(mode_t info)
{
	file_type(info);
	ft_putchar((info & S_IRUSR) ? 'r' : '-');
	ft_putchar((info & S_IWUSR) ? 'w' : '-');
	ft_putchar((info & S_IXUSR) ? 'x' : '-');
	ft_putchar((info & S_IRGRP) ? 'r' : '-');
	ft_putchar((info & S_IWGRP) ? 'w' : '-');
	ft_putchar((info & S_IXGRP) ? 'x' : '-');
	ft_putchar((info & S_IROTH) ? 'r' : '-');
	ft_putchar((info & S_IWOTH) ? 'w' : '-');
	ft_putchar((info & S_IXOTH) ? 'x' : '-');
	ft_putchar(' ');
}
