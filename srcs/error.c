/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:41:17 by alegent           #+#    #+#             */
/*   Updated: 2014/12/09 14:16:05 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_path(char *path)
{
	if (path[ft_strlen(path) - 1] == '/')
	{
		path[ft_strlen(path) - 1] = ':';
		ft_putstr_fd(path, 2);
		ft_putchar_fd(EOL, 2);
		path[ft_strlen(path) - 1] = '/';
	}
	else
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(":\n", 2);
	}
}

static void			print_name(char *path)
{
	if (path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = '\0';
	ft_putstr_fd((ft_strrchr(path, '/') + 1), 2);
	if (path[ft_strlen(path) - 1] == '\0')
		path[ft_strlen(path) - 1] = '/';
}

void				put_error(char *path)
{
	ft_putchar_fd(EOL, 2);
	print_path(path);
	ft_putstr_fd("ft_ls: ", 2);
	print_name(path);
	ft_putstr_fd(": ", 2);
	perror("");
}

void				illegal_error(char *option)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putstr_fd((ft_strchr(option, OPT) + 1), 2);
	ft_putstr_fd("\nusage: ft_ls [-Ralrt] [file ...]\n", 2);
}
