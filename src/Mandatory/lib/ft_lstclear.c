/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:13:18 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/18 03:40:04 by sben-tay         ###   ########.fr       */
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
	mlx_destroy_image(data->mlx_ptr, lst->img->img_ptr);
	ft_free(lst);
}
