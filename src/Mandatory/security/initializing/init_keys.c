/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:59:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/05 04:14:54 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keypress_hook(int keycode, t_game *data)
{
	t_player	*link;
	t_player	*monster;

	link = data->player[LINK];
	monster = data->player[MONSTER];
    if (keycode == KEY_W)
        link->move_up = true;
    else if (keycode == KEY_S)
        link->move_down = true;
    else if (keycode == KEY_A)
        link->move_left = true;
    else if (keycode == KEY_D)
        link->move_right = true;
    else if (keycode == KEY_UP)
        monster->move_up = true;
    else if (keycode == KEY_DOWN)
        monster->move_down = true;
    else if (keycode == KEY_LEFT)
        monster->move_left = true;
    else if (keycode == KEY_RIGHT)
        monster->move_right = true;
    return (0);
}

int keyrelease_hook(int keycode, t_game *data)
{
	t_player	*link;
	t_player	*monster;

	link = data->player[LINK];
	monster = data->player[MONSTER];
    if (keycode == KEY_W)
        link->move_up = false;
    else if (keycode == KEY_S)
        link->move_down = false;
    else if (keycode == KEY_A)
        link->move_left = false;
    else if (keycode == KEY_D)
        link->move_right = false;
    else if (keycode == KEY_UP)
        monster->move_up = false;
    else if (keycode == KEY_DOWN)
        monster->move_down = false;
    else if (keycode == KEY_LEFT)
        monster->move_left = false;
    else if (keycode == KEY_RIGHT)
        monster->move_right = false;
    link->anime_actived = -1;
    monster->anime_actived = -1;
    return (0);
}




// bool	is_walkable(t_game *data, int x, int y);

// int	keypress_hook(int keycode, t_game *data)
// {
// 	t_player	*link;

// 	link = data->player[LINK];
// 	if (keycode == KEY_W)
// 	{
// 		if (!is_walkable(data, link->pos_x + 32, link->pos_y + 15))
// 			// ALL OK ! !
// 			return (0);
// 		link->pos_y -= 7;
// 		link->anime_actived = MOVE_UP;
// 	}
// 	else if (keycode == KEY_S)
// 	{
// 		if (!is_walkable(data, link->pos_x + 30, link->pos_y + 60))
// 			// y OK
// 			return (0);
// 		link->pos_y += 7;
// 		link->anime_actived = MOVE_DOWN;
// 	}
// 	else if (keycode == KEY_A)
// 	{
// 		if (!is_walkable(data, link->pos_x + 15, link->pos_y + 40))
// 			// ALL OK ! !
// 			return (0);
// 		link->pos_x -= 7;
// 		link->anime_actived = MOVE_LEFT;
// 	}
// 	else if (keycode == KEY_D)
// 	{
// 		if (!is_walkable(data, link->pos_x + 52, link->pos_y + 52))
// 			// x & y OK ! !
// 			return (0);
// 		link->pos_x += 7;
// 		link->anime_actived = MOVE_RIGHT;
// 	}
// 	// keypress_hook_m(keycode, data);
// 	update_animation(data, LINK);
// 	return (0);
// }

// int	keyrelease_hook(int keycode, t_game *data)
// {
// 	t_player	*link;

// 	link = data->player[LINK];
// 	if (keycode == KEY_W)
// 	{
// 		draw_static_frame(data, data->pos_static[MOVE_UP], LINK);
// 	}
// 	else if (keycode == KEY_S)
// 	{
// 		draw_static_frame(data, data->pos_static[MOVE_DOWN], LINK);
// 	}
// 	else if (keycode == KEY_A)
// 	{
// 		draw_static_frame(data, data->pos_static[MOVE_LEFT], LINK);
// 	}
// 	else if (keycode == KEY_D)
// 	{
// 		draw_static_frame(data, data->pos_static[MOVE_RIGHT], LINK);
// 	}
// 	link->anime_actived = -1;
// 	// keyrelease_hook_m(keycode, data);
// 	return (0);
// }

// void	draw_rectangle(t_game *data, int x, int y, int width, int height,
// 		int color)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (j < height)
// 	{
// 		i = 0;
// 		while (i < width)
// 		{
// 			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, color);
// 			i++;
// 		}
// 		j++;
// 	}
// }

// bool	is_walkable(t_game *data, int x, int y)
// {
// 	int	map_x;
// 	int	map_y;

// 	// Convertir les coordonnées en indices de la carte
// 	map_x = x / 64;
// 	map_y = y / 64;
// 	// Vérifier les limites de la carte
// 	if (map_x < 0 || map_y < 0 || map_x >= data->map_width
// 		|| map_y >= data->map_height)
// 	{
// 		draw_rectangle(data, x, y, map_x, map_y, 0xFF0000);
// 		return (false); // Hors de la carte, non franchissable
// 	}
// 	// Vérifier si la position est franchissable
// 	if (data->map[map_y][map_x] == '1')
// 	{
// 		draw_rectangle(data, x, y, map_x, map_y, 0xFF0000);
// 		return (false); // Zone non franchissable
// 	}
// 	return (true); // Zone franchissable
// }
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
