/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 05:28:32 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/11 10:52:01 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_lstdelone_garbage(t_garbage *lst);
static void	ft_lstclear_garbage(t_garbage **lst);


void	ft_free_all(t_garbage **lst)
{
	if (!lst)
		return ;
	ft_lstclear_garbage(lst);
}

static void	ft_lstdelone_garbage(t_garbage *lst)
{
	if (!lst)
		return ;
	if (lst->alloc != NULL)
		ft_free((char *)lst->alloc);
	if (lst->allocs != NULL)
		free_split((char **)lst->allocs);
	if (lst->animations != NULL)
		free_split(lst->animations);
	ft_free(lst);
}


static void	ft_lstclear_garbage(t_garbage **lst)
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

