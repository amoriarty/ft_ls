/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 16:26:11 by alegent           #+#    #+#             */
/*   Updated: 2014/12/31 13:09:47 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_link(char *path)
{
	size_t			link_len;
	char			link[BUFF_SIZE];

	ft_bzero(link, BUFF_SIZE);
	link_len = readlink(path, link, BUFF_SIZE);
	link[link_len] = '\0';
	ft_putstr(" -> ");
	ft_putstr(link);
}
