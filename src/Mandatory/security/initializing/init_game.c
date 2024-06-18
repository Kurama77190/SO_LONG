/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:27:43 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/18 14:41:24 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_init_game(t_game *data)
{
	data->memory_manager = NULL;
	data->anim_actived = -1;
	data->pos_char_x = 400;
	data->pos_char_y = 300;
	ft_calloc(1, sizeof(t_game), data->memory_manager, "GAME");
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "so_long");
	init_animations(data);
	return ;
}
