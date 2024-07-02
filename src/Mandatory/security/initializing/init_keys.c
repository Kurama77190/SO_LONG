/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:59:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/02 09:20:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool is_walkable(t_game *data, int x, int y);

int	keypress_hook(int keycode, t_game *data)
{
	if (!is_walkable(data, data->pos_char_x + 5, data->pos_char_y + 5))
		return (0);
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

int	keyrelease_hook(int keycode, t_game *data)
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

bool is_walkable(t_game *data, int x, int y)
{
    // Convertir les coordonnées en indices de la carte
    int map_x = x / 64;
    int map_y = y / 64;

    // Vérifier les limites de la carte
    if (map_x < 0 || map_y < 0 || map_x >= data->map_width || map_y >= data->map_height)
        return false; // Hors de la carte, non franchissable

    // Vérifier si la position est franchissable
    if (data->map[map_y][map_x] == '1')
        return false; // Zone non franchissable

    return true; // Zone franchissable
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

