/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 12:37:36 by alegent           #+#    #+#             */
/*   Updated: 2014/11/26 12:52:53 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	(*del)((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
