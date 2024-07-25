/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:05:05 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 02:12:49 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void				alloc_and_secure_1(t_game *data);
void				alloc_and_secure_2(t_game *data);
void				alloc_and_secure_3(t_game *data);
void				secure_exit(t_game *data);

static const char	*g_x_assets[6] = {
	"src/Mandatory/img/maps/exit2.xpm",
	"src/Mandatory/img/maps/floor1.xpm",
	"src/Mandatory/img/maps/tree.xpm",
	"src/Mandatory/img/maps/floor2.xpm",
	"src/Mandatory/img/maps/rubis.xpm",
	NULL
};

static const char	*g_x_static_player[5] = {
	"src/Mandatory/img/sheetsprite/static/XPM/link_static_up.xpm",
	"src/Mandatory/img/sheetsprite/static/XPM/link_static_down.xpm",
	"src/Mandatory/img/sheetsprite/static/XPM/link_static_left.xpm",
	"src/Mandatory/img/sheetsprite/static/XPM/link_static_right.xpm",
	NULL
};

static const char	*g_x_static_monster[5] = {
	"src/Mandatory/img/monster/static/XPM/monster_static_up.xpm",
	"src/Mandatory/img/monster/static/XPM/monster_static_down.xpm",
	"src/Mandatory/img/monster/static/XPM/monster_static_left.xpm",
	"src/Mandatory/img/monster/static/XPM/monster_static_right.xpm",
	NULL
};

void	init_img(t_game *data)
{
	alloc_and_secure_1(data);
	alloc_and_secure_2(data);
	alloc_and_secure_3(data);
	load_image(data, data->pos_static[MOVE_UP], g_x_static_player[0]);
	load_image(data, data->pos_static[MOVE_DOWN], g_x_static_player[1]);
	load_image(data, data->pos_static[MOVE_LEFT], g_x_static_player[2]);
	load_image(data, data->pos_static[MOVE_RIGHT], g_x_static_player[3]);
	load_image(data, data->assets[EXIT], g_x_assets[0]);
	load_image(data, data->assets[FLOOR], g_x_assets[1]);
	load_image(data, data->assets[WALL], g_x_assets[2]);
	load_image(data, data->assets[RUBIS], g_x_assets[4]);
	load_image(data, data->pos_static[MOVE_UP_M], g_x_static_monster[0]);
	load_image(data, data->pos_static[MOVE_DOWN_M], g_x_static_monster[1]);
	load_image(data, data->pos_static[MOVE_LEFT_M], g_x_static_monster[2]);
	load_image(data, data->pos_static[MOVE_RIGHT_M], g_x_static_monster[3]);
}

// alloc for LINK

void	alloc_and_secure_1(t_game *data)
{
	data->bg_img = ft_calloc(1, sizeof(t_game), &data->memory_manager, "MAP");
	if (!data->bg_img)
		secure_exit(data);
	data->pos_static[MOVE_UP] = ft_calloc(1, sizeof(t_img),
			&data->memory_manager, "LINK");
	if (!data->pos_static[MOVE_UP])
		secure_exit(data);
	data->pos_static[MOVE_DOWN] = ft_calloc(1, sizeof(t_img),
			&data->memory_manager, "LINK");
	if (!data->pos_static[MOVE_DOWN])
		secure_exit(data);
	data->pos_static[MOVE_LEFT] = ft_calloc(1, sizeof(t_img),
			&data->memory_manager, "LINK");
	if (!data->pos_static[MOVE_LEFT])
		secure_exit(data);
	data->pos_static[MOVE_RIGHT] = ft_calloc(1, sizeof(t_img),
			&data->memory_manager, "LINK");
	if (!data->pos_static[MOVE_RIGHT])
		secure_exit(data);
}

// alloc for MONSTER

void	alloc_and_secure_2(t_game *data)
{
	data->pos_static[MOVE_UP_M] = ft_calloc(1, sizeof(t_img),
			&data->memory_manager, "MONSTER");
	if (!data->pos_static[MOVE_UP_M])
		secure_exit(data);
	data->pos_static[MOVE_DOWN_M] = ft_calloc(1, sizeof(t_img),
			&data->memory_manager, "MONSTER");
	if (!data->pos_static[MOVE_DOWN_M])
		secure_exit(data);
	data->pos_static[MOVE_LEFT_M] = ft_calloc(1, sizeof(t_img),
			&data->memory_manager, "MONSTER");
	if (!data->pos_static[MOVE_LEFT_M])
		secure_exit(data);
	data->pos_static[MOVE_RIGHT_M] = ft_calloc(1, sizeof(t_img),
			&data->memory_manager, "MONSTER");
	if (!data->pos_static[MOVE_RIGHT_M])
		secure_exit(data);
}

// alloc for MAP

void	alloc_and_secure_3(t_game *data)
{
	data->assets[EXIT] = ft_calloc(1, sizeof(t_img), &data->memory_manager,
			"MAP");
	if (!data->assets[EXIT])
		secure_exit(data);
	data->assets[FLOOR] = ft_calloc(1, sizeof(t_img), &data->memory_manager,
			"MAP");
	if (!data->assets[FLOOR])
		secure_exit(data);
	data->assets[WALL] = ft_calloc(1, sizeof(t_img), &data->memory_manager,
			"MAP");
	if (!data->assets[WALL])
		secure_exit(data);
	data->assets[RUBIS] = ft_calloc(1, sizeof(t_img), &data->memory_manager,
			"MAP");
	if (!data->assets[RUBIS])
		secure_exit(data);
}
