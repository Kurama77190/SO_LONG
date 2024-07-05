/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:45:30 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/05 03:59:51 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_background_region(t_game *data, int x, int y, int width, int height)
{
    int j = 0;
    while (j < height)
    {
        int i = 0;
        while (i < width)
        {
            int pixel = *(int *)(data->buffer->addr + (y + j) * data->buffer->line_length + (x + i) * (data->buffer->bpp / 8));
            put_pixel_to_image(data->buffer, x + i, y + j, pixel);
            // mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, pixel);
            i++;
        }
        j++;
    }
}

void    draw_background(t_game *data)
{
    if (data->bg_img == NULL)
    {
        fprintf(stderr, "Failed to load background image\n");
        ft_free_all(&data->memory_manager);
        exit(EXIT_FAILURE);
    }
    else
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bg_img->img_ptr, 0, 0);
}


void    draw_animation_frame(t_game *data, t_animation *anim, int x, int y)
{
    t_frame *index;

	index = anim->current;
    draw_background_region(data, x, y, index->img->width, index->img->height);
	if (index)
		draw_image_with_transparency(data, index->img, x, y);
}


void    draw_static_frame(t_game *data, t_img *static_img, e_AnimationType n_player)
{
    t_player *player;

    player = data->player[n_player];
    draw_background_region(data, player->pos_x, player->pos_y, static_img->width, static_img->height);
    if (static_img)
    {
        draw_image_with_transparency(data, static_img, player->pos_x, player->pos_y);
    }
}

void	draw_image_to_image(t_img *dest_img, t_img *src_img, int x, int y)
{
	int	color;

	int src_x, src_y;
	src_y = 0;
	while (src_y < src_img->height)
	{
		src_x = 0;
		while (src_x < src_img->width)
		{
			color = *(unsigned int *)(src_img->addr + src_y
					* src_img->line_length + src_x * (src_img->bpp / 8));
			if (color != 0x489848)
			{
				put_pixel_to_image(dest_img, x + src_x, y + src_y, color);
			}
			src_x++;
		}
		src_y++;
	}
}

// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠈⢆⠀⠀⠀⠈⣹⣷⣀⣴⠀⢠⣤⣶⡦⠀⠀⠀⠀⠀⠀
// ⠢⣀⠀⠀⠀⠀⠀⢄⠀⠈⣆⣠⣼⣿⣿⣿⣿⣿⣦⣼⣏⡀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠈⠻⣶⣄⡀⠀⣨⣷⡿⠟⠋⠉⠉⠉⠉⠛⠿⣿⣿⣿⣧⣀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠙⢿⣿⡿⠋⠀⠀⠀⠀⢠⡄⠀⠀⠀⠈⠙⣿⣿⣏⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⣠⣿⣿⣆⠀⠀⠀⠀⠈⣿⣿⡁⠀⠀⠀⠀⠀
// ⠀⠀⠀⠒⢺⣿⠁⠀⠀⠀⠀⡰⠿⠿⠿⠿⢆⠀⠀⠀⠀⠸⣿⡿⠃⠀⠀⠀⠀
// ⠀⠀⠀⢠⣾⣿⠀⠀⠀⠀⣴⣷⡀⠀⠀⢀⣼⣦⠀⠀⠀⠀⣿⣿⠆⠀⠀⠀⠀
// ⠀⠀⠀⠀⣹⣿⠀⠀⠀⣼⣿⣿⣷⡀⢀⣾⣿⣿⣧⡀⠀⢠⣿⡧⠤⠀⠀⠀⠀
// ⠀⠀⠀⠈⠛⢿⣆⠀⠈⠉⠉⠉⠉⠉⠈⠉⠉⠉⠉⠁⠀⣼⡿⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠻⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣷⣄⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠚⢻⣿⣿⣦⣄⡀⠀⠀⠀⠀⢀⣠⣶⣿⡋⠀⠈⠙⠻⣦⡀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⢙⣿⠿⢿⣿⣿⣿⣿⣿⠛⠙⡁⠀⠁⠀⠀⠀⠀⠀⠉⠂⠄
// ⠀⠀⠀⠀⠀⠰⣶⡾⠿⠀⠸⠋⠻⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//		© 2024 - sben-tay - 42 PARIS
