/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 09:51:09 by alegent           #+#    #+#             */
/*   Updated: 2014/11/28 10:37:58 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_ls.h"
#include "struct.h"

void				ft_error(char *error, char *file)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(error, 2);
	if (file != NULL)
		ft_putstr_fd(ft_strrchr(file, OPT) + 1, 2);
	ft_putchar_fd(EOL, 2);
	ft_putstr_fd("usage: ft_ls [-Rlart] [file ...]\n", 2);
	exit(ERROR);
}
