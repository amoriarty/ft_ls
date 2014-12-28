/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 13:00:54 by alegent           #+#    #+#             */
/*   Updated: 2014/12/28 14:32:09 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				putcolor(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putendl(CANCEL);
}
