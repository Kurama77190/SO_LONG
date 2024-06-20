/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:33:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/20 02:23:17 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void				load_animation(t_game *data, e_AnimationType action,
						const char *paths[]);

static const char	*g_x_move_down[10] = {
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_1.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_2.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_3.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_4.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_5.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_6.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_7.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_8.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_9.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_10.xpm"};

static const char	*g_x_move_up[10] = {
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_1.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_2.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_3.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_4.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_5.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_6.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_7.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_8.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_9.xpm",
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_10.xpm"};

static const char	*g_x_move_left[10] = {
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_1.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_2.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_3.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_4.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_5.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_6.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_7.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_8.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_9.xpm",
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_10.xpm"};

static const char	*g_x_move_right[10] = {
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_1.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_2.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_3.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_4.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_5.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_6.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_7.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_8.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_9.xpm",
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_10.xpm"};

void	init_animations(t_game *data)
{
	load_animation(data, MOVE_DOWN, g_x_move_down);
	load_animation(data, MOVE_UP, g_x_move_up);
	load_animation(data, MOVE_LEFT, g_x_move_left);
	load_animation(data, MOVE_RIGHT, g_x_move_right);
	data->bg_img = ft_calloc(1, sizeof(t_game), data->memory_manager, "IMG_BG");
	data->pos_static[MOVE_UP] = ft_calloc(1, sizeof(t_game), \
			data->memory_manager, "STATIC_IMG_UP");
	data->pos_static[MOVE_DOWN] = ft_calloc(1, sizeof(t_game), \
			data->memory_manager, "STATIC_IMG_DOWN");
	data->pos_static[MOVE_LEFT] = ft_calloc(1, sizeof(t_game), \
			data->memory_manager, "STATIC_IMG_LEFT");
	data->pos_static[MOVE_RIGHT] = ft_calloc(1, sizeof(t_game), \
			data->memory_manager, "STATIC_IMG_RIGHT");
	load_image(data, data->bg_img, "src/Mandatory/img/maps/maps_test.xpm");
	load_image(data, data->pos_static[MOVE_UP], \
		"src/Mandatory/img/sheetsprite/static/XPM/link_static_up.xpm");
	load_image(data, data->pos_static[MOVE_DOWN], \
		"src/Mandatory/img/sheetsprite/static/XPM/link_static_down.xpm");
	load_image(data, data->pos_static[MOVE_LEFT], \
		"src/Mandatory/img/sheetsprite/static/XPM/link_static_left.xpm");
	load_image(data, data->pos_static[MOVE_RIGHT], \
		"src/Mandatory/img/sheetsprite/static/XPM/link_static_right.xpm");
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

