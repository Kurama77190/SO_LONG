/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_walkable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 05:18:37 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/08 07:05:47 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pos_exit(t_game *data);
void	open_exit(t_game *data);

bool	is_walkable(t_game *data, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = x / 64;
	map_y = y / 64;
	open_exit(data);
	if (data->map[map_y][map_x] == '1')
		return (false);
	if (data->map[map_y][map_x] == 'C')
	{
		data->ruby_counter--;
		data->map[map_y][map_x] = '0';
		draw_image_to_image(data->bg_img, data->assets[FLOOR], map_x * 64, map_y
			* 64);
		return (true);
	}
	if (data->map[map_y][map_x] == 'M')
	{
		data->a_life = false;
		return (true);
	}
	return (true);
}

bool	is_walkable_m(t_game *data, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = x / 64;
	map_y = y / 64;
	if (data->map[map_y][map_x] == '1')
	{
		return (false);
	}
	if (data->map[map_y][map_x] == 'C')
		return (true);
	if (data->map[map_y][map_x] == 'P')
	{
		data->a_life = false;
		return (true);
	}
	return (true);
}

void	get_pos_exit(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
			{
				data->exit_x = x;
				data->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	open_exit(t_game *data)
{
	get_pos_exit(data);
	if (data->ruby_counter == 0)
	{
		draw_image_to_image(data->bg_img, data->assets[EXIT], data->exit_x * 64,
			data->exit_y * 64);
	}
}
