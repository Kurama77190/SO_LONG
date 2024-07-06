/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:59:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/06 19:04:00 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    link_press(t_game *data, t_player *link, int keycode);
void    monster_press(t_game *data, t_player *monster, int keycode);

int keypress_hook(int keycode, t_game *data)
{
	t_player	*link;
	t_player	*monster;

	link = data->player[LINK];
	monster = data->player[MONSTER];
    link_press(data, link, keycode);
    monster_press(data, monster, keycode);


    return (0);
}


void    link_press(t_game *data, t_player *link, int keycode)
{
    (void)data;
    if (keycode == KEY_W)
    {
        // if (is_walkable(data, link->pos_x + 32, link->pos_y + 15))
            link->move_up = true;
    }
    else if (keycode == KEY_S)
    {
        // if (is_walkable(data, link->pos_x + 30, link->pos_y + 60))
            link->move_down = true;
    }
    else if (keycode == KEY_A)
    {
        // if (is_walkable(data, link->pos_x + 15, link->pos_y + 40))
            link->move_left = true;
    }
    else if (keycode == KEY_D)
    {
        // if (is_walkable(data, link->pos_x + 52, link->pos_y + 52))
            link->move_right = true;
    }
    if (link->move_up || link->move_down || link->move_left || link->move_right)
        link->anime_actived = 1;
}

void    monster_press(t_game *data, t_player *monster, int keycode)
{
    (void)data;
    if (keycode == KEY_UP)
    {
        // if (is_walkable(data, monster->pos_x + 32, monster->pos_y + 15))
            monster->move_up = true;
    }
    else if (keycode == KEY_DOWN)
    {
        // if (is_walkable(data, monster->pos_x + 30, monster->pos_y + 60))
            monster->move_down = true;
    }
    else if (keycode == KEY_LEFT)
    {
        // if (is_walkable(data, monster->pos_x + 15, monster->pos_y + 40))
            monster->move_left = true;
    }
    else if (keycode == KEY_RIGHT)
    {
        // if (is_walkable(data, monster->pos_x + 52, monster->pos_y + 52))
        monster->move_right = true;
    }
    if (monster->move_up || monster->move_down || monster->move_left || monster->move_right)
        monster->anime_actived = 1;
}

int keyrelease_hook(int keycode, t_game *data)
{
	t_player	*link;
	t_player	*monster;

	link = data->player[LINK];
	monster = data->player[MONSTER];
    if (keycode == KEY_W)
        link->move_up = false;
    if (keycode == KEY_S)
        link->move_down = false;
    if (keycode == KEY_A)
        link->move_left = false;
    if (keycode == KEY_D)
        link->move_right = false;
    if (keycode == KEY_UP)
        monster->move_up = false;
    if (keycode == KEY_DOWN)
        monster->move_down = false;
    if (keycode == KEY_LEFT)
        monster->move_left = false;
    if (keycode == KEY_RIGHT)
        monster->move_right = false;
    link->anime_actived = -1;
    monster->anime_actived = -1;
    return (0);
}


void	draw_rectangle(t_game *data, int x, int y, int width, int height,
		int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

// bool is_walkable(t_game *data, int x, int y)
// {
//     int map_x = x / 64;
//     int map_y = y / 64;

//     // Vérifiez les limites de la carte
//     if (map_x < 0 || map_y < 0 || map_x >= data->map_width || map_y >= data->map_height)
//     {
//         draw_rectangle(data, x, y, 64, 64, 0xFF0000);
//         return false; // Hors de la carte, non franchissable
//     }

//     // Vérifiez si la position est franchissable
//     if (data->map[map_y][map_x] == '1')
//     {
//         draw_rectangle(data, x, y, 64, 64, 0xFF0000);
//         return false; // Zone non franchissable
//     }

//     // Vérifiez les coins
//     if (data->map[(y + 48) / 64][map_x] == '1' || data->map[map_y][(x + 48) / 64] == '1' || 
//         data->map[(y + 48) / 64][(x + 48) / 64] == '1')
//     {
//         draw_rectangle(data, x, y, 64, 64, 0xFF0000);
//         return false; // Zone non franchissable
//     }

//     return true; // Zone franchissable
// }


bool	is_walkable(t_game *data, int x, int y)
{
	int	map_x;
	int	map_y;

	// Convertir les coordonnées en indices de la carte
	map_x = x / 64;
	map_y = y / 64;
	// Vérifier les limites de la carte
	if (map_x < 0 || map_y < 0 || map_x >= data->map_width
		|| map_y >= data->map_height)
	{
		draw_rectangle(data, x, y, map_x, map_y, 0xFF0000);
		return (false); // Hors de la carte, non franchissable
	}
	// Vérifier si la position est franchissable
	if (data->map[map_y][map_x] == '1')
	{
		draw_rectangle(data, x, y, map_x, map_y, 0xFF0000);
		return (false); // Zone non franchissable
	}
	return (true); // Zone franchissable...
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
