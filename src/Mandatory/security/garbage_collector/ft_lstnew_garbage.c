/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_garbage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:15:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/06 19:01:15 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_garbage	*ft_lstnew_garbage(t_garbage **aslt, void *content, void **split)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (!new)
	{
		ft_free_all(aslt);
		perror("allocation for garbage collector from new_node failed\n");
		exit(2);
	}
	new->alloc = NULL;
	new->allocs = NULL;
	if (content)
		new->alloc = content;
	if (split)
		new->allocs = split;
	new->next = NULL;
	return (new);
}
