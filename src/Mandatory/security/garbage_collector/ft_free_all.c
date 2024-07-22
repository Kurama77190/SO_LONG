/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 05:28:32 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/22 01:57:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_free_img(&data->pos_static[MOVE_UP], data->mlx_ptr);
	ft_free_img(&data->pos_static[MOVE_DOWN], data->mlx_ptr);
	ft_free_img(&data->pos_static[MOVE_LEFT], data->mlx_ptr);
	ft_free_img(&data->pos_static[MOVE_RIGHT], data->mlx_ptr);
	ft_free_img(&data->pos_static[MOVE_UP_M], data->mlx_ptr);
	ft_free_img(&data->pos_static[MOVE_DOWN_M], data->mlx_ptr);
	ft_free_img(&data->pos_static[MOVE_LEFT_M], data->mlx_ptr);
	ft_free_img(&data->pos_static[MOVE_RIGHT_M], data->mlx_ptr);
	ft_free_img(&data->assets[EXIT], data->mlx_ptr);
	ft_free_img(&data->assets[FLOOR], data->mlx_ptr);
	ft_free_img(&data->assets[WALL], data->mlx_ptr);
	ft_free_img(&data->assets[RUBIS], data->mlx_ptr);
	ft_free_img(&data->buffer, data->mlx_ptr);
	ft_free_img(&data->bg_img, data->mlx_ptr);
	free_split(data->map);
	ft_lstclear_garbage(lst);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_free(&data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
