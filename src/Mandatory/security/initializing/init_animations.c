/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:33:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 05:55:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const char	*g_x_move_down[11] = {
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_1.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_2.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_3.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_4.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_5.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_6.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_7.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_8.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_9.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_10.xpm",
	NULL};

static const char	*g_x_move_up[11] = {
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_1.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_2.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_3.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_4.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_5.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_6.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_7.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_8.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_9.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_10.xpm",
	NULL};

static const char	*g_x_move_left[11] = {
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_1.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_2.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_3.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_4.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_5.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_6.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_7.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_8.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_9.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_10.xpm",
	NULL};

static const char	*g_x_move_right[11] = {
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_1.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_2.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_3.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_4.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_5.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_6.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_7.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_8.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_9.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_10.xpm",
	NULL};

static const char	*g_x_move_down_m[5] = {
	"src/Mandatory/img/monster/down/XPM/monster_move_down_1.xpm",
	"src/Mandatory/img/monster/down/XPM/monster_move_down_2.xpm",
	"src/Mandatory/img/monster/down/XPM/monster_move_down_3.xpm",
	"src/Mandatory/img/monster/down/XPM/monster_move_down_4.xpm",
	NULL};

static const char	*g_x_move_up_m[5] = {
	"src/Mandatory/img/monster/up/XPM/monster_move_up_1.xpm",
	"src/Mandatory/img/monster/up/XPM/monster_move_up_2.xpm",
	"src/Mandatory/img/monster/up/XPM/monster_move_up_3.xpm",
	"src/Mandatory/img/monster/up/XPM/monster_move_up_4.xpm",
	NULL};

static const char	*g_x_move_left_m[5] = {
	"src/Mandatory/img/monster/left/XPM/monster_move_left_1.xpm",
	"src/Mandatory/img/monster/left/XPM/monster_move_left_2.xpm",
	"src/Mandatory/img/monster/left/XPM/monster_move_left_3.xpm",
	"src/Mandatory/img/monster/left/XPM/monster_move_left_4.xpm",
	NULL};

static const char	*g_x_move_right_m[5] = {
	"src/Mandatory/img/monster/right/XPM/monster_move_right_1.xpm",
	"src/Mandatory/img/monster/right/XPM/monster_move_right_2.xpm",
	"src/Mandatory/img/monster/right/XPM/monster_move_right_3.xpm",
	"src/Mandatory/img/monster/right/XPM/monster_move_right_4.xpm",
	NULL};

void	init_animations(t_game *data)
{
	load_animation(data, MOVE_DOWN, g_x_move_down);
	load_animation(data, MOVE_UP, g_x_move_up);
	load_animation(data, MOVE_LEFT, g_x_move_left);
	load_animation(data, MOVE_RIGHT, g_x_move_right);
	load_animation(data, MOVE_DOWN_M, g_x_move_down_m);
	load_animation(data, MOVE_UP_M, g_x_move_up_m);
	load_animation(data, MOVE_LEFT_M, g_x_move_left_m);
	load_animation(data, MOVE_RIGHT_M, g_x_move_right_m);
	return ;
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
