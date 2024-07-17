/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:13:18 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/17 21:00:42 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstdelone(t_frame *lst, t_game *data);

void	ft_lstclear(t_frame **lst, t_game *data)
{
	t_frame	*current;

	if (!lst || !*lst)
		return ;
	while (lst != NULL && *lst != NULL)
	{
		current = (*lst)->next;
		ft_lstdelone(*lst, data);
		*lst = current;
	}
}

void	ft_lstdelone(t_frame *lst, t_game *data)
{
	if (!lst || !data)
		return ;
	if (lst->img && lst->img->img_ptr)
		ft_free_img(&lst->img, data->mlx_ptr);
	ft_free((void **)&lst);
}
