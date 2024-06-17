/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:25:18 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/17 05:59:42 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_animation(t_game *data, e_AnimationType action, \
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
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_10.xpm"
};

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
	"src/Mandatory/img/sheetsprite/up/XPM/link_move_up_10.xpm"
};

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
	"src/Mandatory/img/sheetsprite/left/XPM/link_move_left_10.xpm"
};

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
	"src/Mandatory/img/sheetsprite/right/XPM/link_move_right_10.xpm"
};


void	ft_init_animation(t_game *data)
{
	load_animation(data, MOVE_DOWN, g_x_move_down);
	load_animation(data, MOVE_UP, g_x_move_up);
	load_animation(data, MOVE_LEFT, g_x_move_left);
	load_animation(data, MOVE_RIGHT, g_x_move_right);
	load_image(data, data->animations[MOVE_UP]->Static, "src/Mandatory/img/sheetsprite/static/XPM/link_static_up.xpm");
	load_image(data, data->animations[MOVE_DOWN]->Static, "src/Mandatory/img/sheetsprite/static/XPM/link_static_down.xpm");
	load_image(data, data->animations[MOVE_LEFT]->Static, "src/Mandatory/img/sheetsprite/static/XPM/link_static_left.xpm");
	load_image(data, data->animations[MOVE_RIGHT]->Static, "src/Mandatory/img/sheetsprite/static/XPM/link_static_right.xpm");
}

void	load_animation(t_game *data, e_AnimationType action, \
			const char *paths[])
{
	size_t		i;
	size_t		j;

	if (!data)
	{
		printf("Error init \n");
		exit(1);
	}
	i = 0;
	j = ft_strslen(paths);
	data->animations[action] = ft_calloc(1, sizeof(t_animation),
			data->memory_manager, "ANIMATION");
	while (i < j)
	{
		printf("numero FRAMES = %li\n", i);
		ft_lstadd_back(&(data->animations[action]->frames),
			ft_lstnew(paths[i], data));
		if (i == 0)
		{
			
			data->animations[action]->current = data->animations[action]->frames;
			data->animations[action]->frame_count = 0;
		}
		i++;
	}
	return ;
}
