/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:27:43 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/05 19:56:59 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_game *data);
void	init_win(t_game *data);
void	init_player(t_game *data, e_AnimationType n_player);

void	ft_init_game(t_game *data)
{
	init_data(data);
	init_player(data, LINK);
	init_player(data, MONSTER);
	init_animations(data);
	init_img(data);
	init_map(data);
	init_win(data);
	
	return ;
}

void	init_data(t_game *data)
{
	data->memory_manager = NULL;
	data->mlx_ptr = mlx_init();
	
}

void	init_player(t_game *data, e_AnimationType n_player)
{
	data->player[n_player] = ft_calloc(1, sizeof(t_player), \
			data->memory_manager, "PLAYER");
	if (!data->player[n_player])
		secure_exit(data);

	data->player[n_player]->pos_x = 0;
	data->player[n_player]->pos_y = 0;
	data->player[n_player]->anime_actived = -1;
	data->player[n_player]->last_direction = MOVE_DOWN;
	data->player[n_player]->move_down = false;
	data->player[n_player]->move_up = false;
	data->player[n_player]->move_left = false;
	data->player[n_player]->move_right = false;
}

void	init_win(t_game *data)
{
	printf("creation de la fenetre :\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_width * 64, \
			data->map_height * 64, "The Legend of Zelda : A link to MLX");
	printf("win_ptr = %p\n", data->win_ptr);
	draw_image_to_image(data->buffer, data->bg_img, 0, 0);
	draw_image_with_transparency(data, data->pos_static[MOVE_DOWN], 
		data->player[LINK]->pos_x, data->player[LINK]->pos_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buffer->img_ptr, data->player[LINK]->pos_x, data->player[LINK]->pos_y);
	printf("pos_char_x = %d\n", data->player[LINK]->pos_x);
	printf("pos_char_y = %d\n", data->player[LINK]->pos_y);
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

