/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 12:57:28 by alegent           #+#    #+#             */
/*   Updated: 2014/11/26 13:11:32 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;
	t_list		*tmp;

	list = (*alst);
	while (list)
	{
		tmp = list->next;
		(*del)(list->content, list->content_size);
		free(list);
		list = tmp;
	}
	(*alst) = NULL;
}
