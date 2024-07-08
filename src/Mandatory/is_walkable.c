/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_walkable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 05:18:37 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/08 19:25:27 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pos_exit(t_game *data);
void	open_exit(t_game *data);
void	set_hitbox(t_game *data, t_player *link, t_player *monster);

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
	if (data->map[map_y][map_x] == 'E')
	{
		if (data->ruby_counter == 0)
		{
			ft_free_all(&data->memory_manager, data);
			exit(EXIT_SUCCESS);
		}
		else
			return true;
	}
	return (true);
}

bool	is_walkable_m(t_game *data, int x, int y)
{
	int			map_x;
	int			map_y;
	t_player	*monster;
	t_player	*link;

	map_x = x / 64;
	map_y = y / 64;
	link = data->player[LINK];
	monster = data->player[MONSTER];
	set_hitbox(data, link, monster);
	if (data->map[map_y][map_x] == '1')
	{
		return (false);
	}
	if (data->map[map_y][map_x] == 'C')
		return (true);
	if (monster->hitbox_right >= link->hitbox_left
		&& monster->hitbox_left <= link->hitbox_right
		&& monster->hitbox_down >= link->hitbox_up
		&& monster->hitbox_up <= link->hitbox_down)
	{
		data->a_life = false;
		return (true);
	}
	return (true);
}

void	set_hitbox(t_game *data, t_player *link, t_player *monster)
{
	int	hitbox_s;

	hitbox_s = data->hitbox_size;
	monster->hitbox_left = monster->pos_x - hitbox_s / 2;
	monster->hitbox_right = monster->pos_x + hitbox_s / 2;
	monster->hitbox_up = monster->pos_y - hitbox_s / 2;
	monster->hitbox_down = monster->pos_y + hitbox_s / 2;
	link->hitbox_left = link->pos_x - hitbox_s / 2;
	link->hitbox_right = link->pos_x + hitbox_s / 2;
	link->hitbox_up = link->pos_y - hitbox_s / 2;
	link->hitbox_down = link->pos_y + hitbox_s / 2;

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