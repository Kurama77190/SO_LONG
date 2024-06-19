/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:27:43 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/19 02:27:09 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n);

void	ft_init_game(t_game *data)
{
	data->memory_manager = NULL;
	data->anim_actived = -1;
	data->pos_char_x = 400;
	data->pos_char_y = 300;
	data->mlx_ptr = mlx_init();
	init_animations(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->bg_img->width, data->bg_img->height, "The Legend of Zelda : A link to MLX");
	return ;
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
