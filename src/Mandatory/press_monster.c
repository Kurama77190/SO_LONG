/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_monster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:41:34 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 04:03:59 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
