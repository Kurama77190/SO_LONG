/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 05:28:32 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/08 20:03:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_lstdelone_garbage(t_garbage *lst);
static void	ft_lstclear_garbage(t_garbage **lst);


void	ft_free_all(t_garbage **lst, t_game *data)
{
	if (!lst)
		return ;
	ft_lstclear(&data->animations[MOVE_DOWN]->frames, data);
	ft_lstclear(&data->animations[MOVE_DOWN_M]->frames, data);
	ft_lstclear(&data->animations[MOVE_UP]->frames, data);
	ft_lstclear(&data->animations[MOVE_UP_M]->frames, data);
	ft_lstclear(&data->animations[MOVE_RIGHT]->frames, data);
	ft_lstclear(&data->animations[MOVE_RIGHT_M]->frames, data);
	ft_lstclear(&data->animations[MOVE_LEFT]->frames, data);
	ft_lstclear(&data->animations[MOVE_LEFT_M]->frames, data);
	ft_free_img(data->pos_static[MOVE_UP]->img_ptr, data->mlx_ptr);
	ft_free_img(data->pos_static[MOVE_DOWN]->img_ptr, data->mlx_ptr);
	ft_free_img(data->pos_static[MOVE_LEFT]->img_ptr, data->mlx_ptr);
	ft_free_img(data->pos_static[MOVE_RIGHT]->img_ptr, data->mlx_ptr);
	ft_free_img(data->pos_static[MOVE_UP_M]->img_ptr, data->mlx_ptr);
	ft_free_img(data->pos_static[MOVE_DOWN_M]->img_ptr, data->mlx_ptr);
	ft_free_img(data->pos_static[MOVE_LEFT_M]->img_ptr, data->mlx_ptr);
	ft_free_img(data->pos_static[MOVE_RIGHT_M]->img_ptr, data->mlx_ptr);
	ft_free_img(data->assets[EXIT]->img_ptr, data->mlx_ptr);
	ft_free_img(data->assets[FLOOR]->img_ptr, data->mlx_ptr);
	ft_free_img(data->assets[WALL]->img_ptr, data->mlx_ptr);
	ft_free_img(data->assets[RUBIS]->img_ptr, data->mlx_ptr);
	ft_free_img(data->buffer->img_ptr, data->mlx_ptr);
	ft_free_img(data->bg_img->img_ptr, data->mlx_ptr);
	free_split(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_lstclear_garbage(lst);
	exit(EXIT_SUCCESS);
}

static void	ft_lstdelone_garbage(t_garbage *lst)
{
	if (!lst)
		return ;
	if (lst->alloc != NULL)
		ft_free((char *)lst->alloc);
	if (lst->allocs != NULL)
		free_split((char **)lst->allocs);
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

