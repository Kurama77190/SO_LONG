/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:59:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/23 14:28:58 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	link_press(t_game *data, t_player *link, int keycode);
void	monster_press(t_game *data, t_player *monster, int keycode);

int	keypress_hook(int keycode, t_game *data)
{
	t_player	*link;
	t_player	*monster;

	link = data->player[LINK];
	monster = data->player[MONSTER];
	link_press(data, link, keycode);
	monster_press(data, monster, keycode);
	return (0);
}

void	link_press(t_game *data, t_player *link, int keycode)
{
	(void)data;
	if (keycode == KEY_W)
	{
		if (is_walkable(data, link->pos_x + 32, link->pos_y + 15))
			link->move_up = true;
	}
	else if (keycode == KEY_S)
	{
		if (is_walkable(data, link->pos_x + 30, link->pos_y + 60))
			link->move_down = true;
	}
	else if (keycode == KEY_A)
	{
		if (is_walkable(data, link->pos_x + 15, link->pos_y + 40))
			link->move_left = true;
	}
	else if (keycode == KEY_D)
	{
		if (is_walkable(data, link->pos_x + 52, link->pos_y + 52))
			link->move_right = true;
	}
	if (link->move_up || link->move_down || link->move_left || link->move_right)
		link->anime_actived = 1;
}

void	monster_press(t_game *data, t_player *monster, int keycode)
{
	(void)data;
	if (keycode == KEY_UP)
	{
		if (is_walkable_m(data, monster->pos_x + 32, monster->pos_y + 15))
			monster->move_up = true;
	}
	else if (keycode == KEY_DOWN)
	{
		if (is_walkable_m(data, monster->pos_x + 30, monster->pos_y + 60))
			monster->move_down = true;
	}
	else if (keycode == KEY_LEFT)
	{
		if (is_walkable_m(data, monster->pos_x + 15, monster->pos_y + 40))
			monster->move_left = true;
	}
	else if (keycode == KEY_RIGHT)
	{
		if (is_walkable_m(data, monster->pos_x + 52, monster->pos_y + 52))
			monster->move_right = true;
	}
	if (monster->move_up || monster->move_down || monster->move_left
		|| monster->move_right)
		monster->anime_actived = 1;
}

int	keyrelease_hook(int keycode, t_game *data)
{
	t_player	*link;
	t_player	*monster;

	link = data->player[LINK];
	monster = data->player[MONSTER];
	if (keycode == KEY_W && link->move_up)
		link->move_up = false;
	if (keycode == KEY_S && link->move_down)
		link->move_down = false;
	if (keycode == KEY_A && link->move_left)
		link->move_left = false;
	if (keycode == KEY_D && link->move_right)
		link->move_right = false;
	if (keycode == KEY_UP && monster->move_up)
		monster->move_up = false;
	if (keycode == KEY_DOWN && monster->move_down)
		monster->move_down = false;
	if (keycode == KEY_LEFT && monster->move_left)
		monster->move_left = false;
	if (keycode == KEY_RIGHT && monster->move_right)
		monster->move_right = false;
	link->anime_actived = -1;
	monster->anime_actived = -1;
	return (0);
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
