/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 03:34:38 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 23:21:27 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_ruby_and_exit(t_game *data);
void	draw_floor_and_thee(t_game *data);
void	draw_pos_players(t_game *data);
void	draw_player(t_game *data, int *x, int *y);

void	draw_map(t_game *data)
{
	data->bg_img->img_ptr = mlx_new_image(data->mlx_ptr, data->map_width * 64,
			data->map_height * 64);
	if (data->bg_img->img_ptr == NULL)
	{
		perror("Error.\nFailed to load background image\n");
		ft_free_all(&data->memory_manager, data);
		exit(EXIT_FAILURE);
	}
	data->bg_img->addr = mlx_get_data_addr(data->bg_img->img_ptr,
			&data->bg_img->bpp, &data->bg_img->line_length,
			&data->bg_img->endian);
	draw_floor_and_thee(data);
	draw_ruby_and_exit(data);
	draw_pos_players(data);
}

void	draw_ruby_and_exit(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
			{
				draw_image_to_image(data->bg_img, data->assets[FLOOR], x * 64, y
					* 64);
				draw_image_to_image(data->bg_img, data->assets[RUBIS], x * 64, y
					* 64);
				data->ruby_counter++;
			}
			if (data->map[y][x] == 'E')
			{
				draw_image_to_image(data->bg_img, data->assets[FLOOR], x * 64, y
					* 64);
			}
			x++;
		}
	}
}

void	draw_floor_and_thee(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '0')
			{
				draw_image_to_image(data->bg_img, data->assets[FLOOR], x * 64, y
					* 64);
			}
			if (data->map[y][x] == '1')
			{
				draw_image_to_image(data->bg_img, data->assets[WALL], x * 64, y
					* 64);
			}
			x++;
		}
		y++;
	}
}

void	draw_pos_players(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	draw_player(data, &x, &y);
}

void	draw_player(t_game *data, int *x, int *y)
{
	while (data->map[*y])
	{
		(*x) = 0;
		while (data->map[*y][*x])
		{
			if (data->map[*y][*x] == 'P')
			{
				draw_image_to_image(data->bg_img, data->assets[FLOOR], (*x)
					* 64, (*y) * 64);
				data->player[LINK]->pos_x = *x * 64;
				data->player[LINK]->pos_y = *y * 64;
			}
			if (data->map[*y][*x] == 'M')
			{
				draw_image_to_image(data->bg_img, data->assets[FLOOR], *x * 64,
					*y * 64);
				data->player[MONSTER]->pos_x = *x * 64;
				data->player[MONSTER]->pos_y = *y * 64;
			}
			(*x)++;
		}
		(*y)++;
	}
}
