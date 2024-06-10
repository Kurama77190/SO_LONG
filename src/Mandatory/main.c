/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/10 18:29:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void draw_animation_frame(t_game *data, t_animation *anim, int x, int y)
{
    t_frame *index;

	index = anim->frames;
	if (index->next)
	{
		draw_image_with_transparency(data, anim->frames->img, x, y);
		index = index->next;
    }
}

int key_hook(int keycode, t_game *data)
{
    if (keycode == KEY_W)
	{
        data->pos_char_y -= 10;
		draw_animation_frame(data, data->animations[MOVE_UP], data->pos_char_x, data->pos_char_y);
    } 
	else if (keycode == KEY_S)
	{
        data->pos_char_y += 10;
		draw_animation_frame(data, data->animations[MOVE_DOWN], data->pos_char_x, data->pos_char_y);
    }
	else if (keycode == KEY_A)
	{
        data->pos_char_x -= 10;
		draw_animation_frame(data, data->animations[MOVE_LEFT], data->pos_char_x, data->pos_char_y);
    }
	else if (keycode == KEY_D)
	{
        data->pos_char_x += 10;
		draw_animation_frame(data, data->animations[MOVE_RIGHT], data->pos_char_x, data->pos_char_y);
    }
    return (0);
}

int key_release_hook(int keycode, t_game *data)
{
    if (keycode == KEY_W)
        data->anim_actived = 0;
    return (0);
}

int	main(void)
{
	t_game	data;

	ft_init_game(&data);
	mlx_key_hook(data.win_ptr,key_hook, &data);
	mlx_hook()
	mlx_loop(data.mlx_ptr);
	return (0);
}
