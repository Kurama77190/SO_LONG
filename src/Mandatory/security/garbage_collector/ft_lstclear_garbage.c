/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_garbage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:05:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/17 17:32:35 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstdelone_garbage(t_garbage *lst)
{
	if (!lst)
		return ;
	if (lst->alloc != NULL)
	{
		ft_free((void **)&lst->alloc);
	}
	if (lst->allocs != NULL)
	{
		free_split((char **)&lst->allocs);
	}
	ft_free((void **)&lst);
}

void	ft_lstclear_garbage(t_garbage **lst)
{
	t_garbage	*current;

	if (!lst || !*lst)
		return ;
	while (lst != NULL && *lst != NULL)
	{
		current = (*lst)->next;
		ft_lstdelone_garbage(*lst);
		*lst = current;
	}
}