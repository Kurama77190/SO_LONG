/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 03:34:38 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/06 22:32:30 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	data->bg_img->img_ptr = mlx_new_image(data->mlx_ptr, data->map_width * 64, \
			data->map_height * 64);
	if (data->bg_img->img_ptr == NULL)
	{
		fprintf(stderr, "Failed to load background image\n");
		ft_free_all(&data->memory_manager);
		exit(EXIT_FAILURE);
	}
	data->bg_img->addr = mlx_get_data_addr(data->bg_img->img_ptr,
			&data->bg_img->bpp, &data->bg_img->line_length,
			&data->bg_img->endian);
	while (y < data->map_height)
	{
		while (x < data->map_width && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == '0')
				draw_image_to_image(data->bg_img, data->assets[FLOOR], x * 64, y * 64);
			else if (data->map[i][j] == '1')
				draw_image_to_image(data->bg_img, data->assets[WALL], x * 64, y * 64);
			else if (data->map[i][j] == 'P')
			{
				draw_image_to_image(data->bg_img, data->assets[FLOOR], x * 64, y * 64);
				data->player[LINK]->pos_x = x * 64;
				data->player[LINK]->pos_y = y * 64;
			}
			else if (data->map[i][j] == 'M')
			{
				draw_image_to_image(data->bg_img, data->assets[FLOOR], x * 64, y * 64);
				data->player[MONSTER]->pos_x = x * 64;
				data->player[MONSTER]->pos_y = y * 64;
			}
			else if (data->map[i][j] == 'C')
			{
				draw_image_to_image(data->bg_img, data->assets[FLOOR], x * 64, y * 64);
				draw_image_to_image(data->bg_img, data->assets[RUBIS], x * 64, y * 64);
			}
			x++;
			j++;
		}
		x = 0;
		j = 0;
		i++;
		y++;
	}
}
