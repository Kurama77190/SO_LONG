/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:27:43 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/09 18:23:07 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_win(t_game *data);
void	init_player(t_game *data, e_AnimationType n_player);
float	get_normalization_factor(int map_width, int map_height);

void	ft_init_game(t_game *data)
{
	data->memory_manager = NULL;
	data->all_ruby = 0;
	data->a_life = true;
	data->step_counter = 0;
	data->ruby_counter = 0;
	data->hitbox_size = 16;
	data->mlx_ptr = mlx_init();
	init_animations(data);
	init_img(data);
	init_player(data, LINK);
	init_player(data, MONSTER);
	init_map(data);
	init_win(data);
	return ;
}

void	init_player(t_game *data, e_AnimationType n_player)
{
	data->player[n_player] = ft_calloc(1, sizeof(t_player),
			&data->memory_manager, "PLAYER");
	if (!data->player[n_player])
		secure_exit(data);
	data->player[n_player]->pos_x = 0;
	data->player[n_player]->pos_y = 0;
	data->player[n_player]->anime_actived = -1;
	if (n_player == LINK)
		data->player[n_player]->last_direction = MOVE_DOWN;
	else
		data->player[n_player]->last_direction = MOVE_DOWN_M;
	data->player[n_player]->move_down = false;
	data->player[n_player]->move_up = false;
	data->player[n_player]->move_left = false;
	data->player[n_player]->move_right = false;
}

void	init_win(t_game *data)
{
	t_img		*bg_img;
	t_img		*buffer;
	t_img		**pos_static;
	t_player	*link;
	t_player	*monster;

	buffer = data->buffer;
	bg_img = data->bg_img;
	pos_static = data->pos_static;
	link = data->player[LINK];
	monster = data->player[MONSTER];
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_width * 64,
			data->map_height * 64, "The Legend of Zelda : A link to MLX");
	draw_image_to_image(buffer, bg_img, 0, 0);
	draw_image_to_image(data->buffer, pos_static[MOVE_DOWN], link->pos_x,
		link->pos_y);
	draw_image_to_image(data->buffer, pos_static[MOVE_DOWN_M], monster->pos_x,
		monster->pos_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, buffer->img_ptr, 0,
		0);
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
