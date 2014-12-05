/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:14:40 by alegent           #+#    #+#             */
/*   Updated: 2014/12/05 17:22:47 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				file_type(mode_t info)
{
	if (S_ISDIR(info))
		ft_putchar('d');
	else if (S_ISBLK(info))
		ft_putchar('b');
	else if (S_ISCHR(info))
		ft_putchar('c');
	else if (S_ISFIFO(info))
		ft_putchar('p');
	else if (S_ISLNK(info))
		ft_putchar('l');
	else if (S_ISREG(info))
		ft_putchar('-');
}
