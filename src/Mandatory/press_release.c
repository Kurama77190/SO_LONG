/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:06:17 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/23 16:25:30 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_release_link(t_game *data, int keycode, t_player *link);
void	player_release_monster(t_game *data, int keycode, t_player *monster);
void    reset_frame_count(t_game *data);

int	keyrelease_hook(int keycode, t_game *data)
{
	t_player	*link;
	t_player	*monster;

	link = data->player[LINK];
	monster = data->player[MONSTER];
	player_release_link(data, keycode, link);
	player_release_monster(data, keycode, monster);
	return (0);
}

void	player_release_link(t_game *data, int keycode, t_player *link)
{
	(void)data;
    if (keycode == KEY_W && link->move_up)
	{
		link->move_up = false;
	}
	else if (keycode == KEY_S && link->move_down)
	{
		link->move_down = false;
	}
	else if (keycode == KEY_A && link->move_left)
	{
		link->move_left = false;
	}
	else if (keycode == KEY_D && link->move_right)
	{
		link->move_right = false;
	}
	link->anime_actived = -1;
}


void	player_release_monster(t_game *data, int keycode, t_player *monster)
{
    (void)data;
	if (keycode == KEY_UP && monster->move_up)
	{
		monster->move_up = false;
	}
	else if (keycode == KEY_DOWN && monster->move_down)
	{
		monster->move_down = false;
	}
	else if (keycode == KEY_LEFT && monster->move_left)
	{
		monster->move_left = false;
	}
	else if (keycode == KEY_RIGHT && monster->move_right)
	{
		monster->move_right = false;
	}
	monster->anime_actived = -1;
}