/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:40:51 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 04:13:35 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
