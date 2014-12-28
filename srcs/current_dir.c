/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 09:27:41 by alegent           #+#    #+#             */
/*   Updated: 2014/12/17 10:48:20 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					current_dir(char *dir)
{
	if (ft_strcmp(dir, ".") == 0)
		return (TRUE);
	if (ft_strcmp(dir, "..") == 0)
		return (TRUE);
	if (ft_strcmp(dir, "./") == 0)
		return (TRUE);
	if (ft_strcmp(dir, "../") == 0)
		return (TRUE);
	return (FALSE);
}
