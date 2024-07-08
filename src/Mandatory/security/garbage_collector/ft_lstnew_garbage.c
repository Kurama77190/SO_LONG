/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_garbage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:15:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/08 20:03:55 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_garbage	*ft_lstnew_garbage(t_garbage **aslt, void *content, void **split, char *name)
{
	t_garbage	*new;
	(void)aslt;
	new = malloc(sizeof(t_garbage));
	if (!new)
	{
		return (NULL);
	}
	new->name = NULL;
	new->alloc = NULL;
	new->allocs = NULL;
	if (name)
		new->name = name;
	if (content)
		new->alloc = content;
	if (split)
		new->allocs = split;
	new->next = NULL;
	return (new);
}
