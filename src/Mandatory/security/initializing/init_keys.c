/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:59:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/19 03:03:52 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_background_region(t_game *data, int x, int y, int width, int height)
{
    if (data->bg_img->img_ptr)
    {
        int j = 0;
        while (j < height)
        {
            int i = 0;
            while (i < width)
            {
                int pixel = *(int *)(data->bg_img->addr + (y + j) * data->bg_img->line_length + (x + i) * (data->bg_img->bpp / 8));
                mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, pixel);
                i++;
            }
            j++;
        }
    }
}

void    draw_background(t_game *data)
{
    if (data->bg_img == NULL)
    {
        fprintf(stderr, "Failed to load background image\n");
        ft_free_all(&data->memory_manager);
        exit(2);
    }
    else
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bg_img->img_ptr, 0, 0);
}


void draw_animation_frame(t_game *data, t_animation *anim, int x, int y)
{
    t_frame *index;

	index = anim->current;
    draw_background_region(data, x, y, index->img->width, index->img->height);
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

void draw_static_frame(t_game *data, t_img *static_img)
{
    draw_background_region(data, data->pos_char_x, data->pos_char_y, static_img->width, static_img->height);
    if (static_img)
    {
        draw_image_with_transparency(data, static_img, data->pos_char_x, data->pos_char_y);
    }
}


int keyrelease_hook(int keycode, t_game *data)
{
    
    if (keycode == KEY_W)
    {
        draw_static_frame(data, data->pos_static[MOVE_UP]);
    }
    else if (keycode == KEY_S)
    {
        draw_static_frame(data, data->pos_static[MOVE_DOWN]);
    }
    else if (keycode == KEY_A)
    {
        draw_static_frame(data, data->pos_static[MOVE_LEFT]);
    }
    else if (keycode == KEY_D)
    {
        draw_static_frame(data, data->pos_static[MOVE_RIGHT]);
    }
        data->anim_actived = -1;
    return (0);
}
