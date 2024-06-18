/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:59:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/18 19:41:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void draw_animation_frame(t_game *data, t_animation *anim, int x, int y)
{
    t_frame *index;

	index = anim->current;
	if (index)
		draw_image_with_transparency(data, index->img, x, y);
}

int update_animation(t_game *data)
{
    t_animation *animation;
    t_frame *current;
    if (data->anim_actived == -1)
        return (0);
    animation = data->animations[data->anim_actived];
    current = animation->current;

    if (current != NULL)
    {
        // mlx_clear_window(data->mlx_ptr, data->win_ptr);
        draw_animation_frame(data, animation, data->pos_char_x, data->pos_char_y);
        if (animation->frame_count % 110 == 0)
            animation->current = current->next;
        
        if (animation->current == NULL)
            animation->current = animation->frames;
        animation->frame_count++;
    }
    return (0);
}

int keypress_hook(int keycode, t_game *data)
{
    if (keycode == KEY_W)
    {
        data->pos_char_y -= 5;
        data->anim_actived = MOVE_UP;
    } 
    else if (keycode == KEY_S)
    {
        data->pos_char_y += 5;
        data->anim_actived = MOVE_DOWN;
    }
    else if (keycode == KEY_A)
    {    
        data->pos_char_x -= 5;
        data->anim_actived = MOVE_LEFT;
    }
    else if (keycode == KEY_D)
    {
        data->pos_char_x += 5;
        data->anim_actived = MOVE_RIGHT;
    }
    return (0);
}

int keyrelease_hook(int keycode, t_game *data)
{
    
    if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
    {
        data->anim_actived = -1;
    }
    return (0);
}