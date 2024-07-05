/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key_monster.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 01:39:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/05 02:44:36 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	keypress_hook_m(int keycode, t_game *data)
// {
// 	t_player	*link;
// 	t_player	*monster;

// 	link = data->player[LINK];
// 	monster = data->player[MONSTER];

// 	if (keycode == XK_Up)
// 	{
// 		if (!is_walkable(data, monster->pos_x + 32, monster->pos_y + 15))
// 			// ALL OK ! !
// 			return (0);
// 		monster->pos_y -= 3;
// 		data->anim_actived_m = MOVE_UP_M;
// 	}
// 	else if (keycode == XK_Down)
// 	{
// 		if (!is_walkable(data, data->pos_enemy_x + 30, monster->pos_y + 60))
// 			// y OK
// 			return (0);
// 		monster->pos_y += 3;
// 		data->anim_actived_m = MOVE_DOWN_M;
// 	}
// 	else if (keycode == XK_Left)
// 	{
// 		if (!is_walkable(data, data->pos_enemy_x + 15, monster->pos_y + 40))
// 			// ALL OK ! !
// 			return (0);
// 		data->pos_enemy_x -= 3;
// 		data->anim_actived_m = MOVE_LEFT_M;
// 	}
// 	else if (keycode == XK_Right)
// 	{
// 		if (!is_walkable(data, data->pos_enemy_x + 52, monster->pos_y + 52))
// 			// x & y OK ! !
// 			return (0);
// 		data->pos_enemy_x += 3;
// 		data->anim_actived_m = MOVE_RIGHT_M;
// 	}
// 	// update_animation(data);
// 	return (0);
// }

// int	keyrelease_hook_m(int keycode, t_game *data)
// {
// 	if (keycode == XK_Up)
// 	{
// 		draw_static_frame(data, data->pos_static[MOVE_UP_M]);
// 	}
// 	else if (keycode == XK_Down)
// 	{
// 		draw_static_frame(data, data->pos_static[MOVE_DOWN_M]);
// 	}
// 	else if (keycode == XK_Left)
// 	{
// 		draw_static_frame(data, data->pos_static[MOVE_LEFT_M]);
// 	}
// 	else if (keycode == XK_Right)
// 	{
// 		draw_static_frame(data, data->pos_static[MOVE_RIGHT_M]);
// 	}
// 	data->anim_actived_m = -1;
// 	return (0);
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
