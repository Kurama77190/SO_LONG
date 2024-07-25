/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:45:35 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 01:52:40 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		get_last_direction(t_player *player1, t_player *player2);
void	update_player(t_game *data);
int		update_animation(t_game *data, t_player *player);
int		link_action(t_game *data, t_player *link);
int		monster_action(t_game *data, t_player *monster);

int	update_game(t_game *data)
{
	t_player	*link;
	t_player	*monster;

	link = data->player[LINK];
	monster = data->player[MONSTER];
	link_action(data, link);
	monster_action(data, monster);
	link->last_direction = get_last_direction(link, NULL);
	monster->last_direction = get_last_direction(NULL, monster);
	update_player(data);
    if (!(data->a_life))
    {
        ft_free_all(&data->memory_manager, data);
		exit(EXIT_SUCCESS);
    }
	return (0);
}

int	link_action(t_game *data, t_player *link)
{
	if (link->move_up)
	{
		if (is_walkable(data, link->pos_x + 32, link->pos_y + 15))
			link->pos_y -= M_S_LINK;
	}
	else if (link->move_down)
	{
		if (is_walkable(data, link->pos_x + 30, link->pos_y + 60))
			link->pos_y += M_S_LINK;
	}
	else if (link->move_left)
	{
		if (is_walkable(data, link->pos_x + 15, link->pos_y + 40))
			link->pos_x -= M_S_LINK;
	}
	else if (link->move_right)
	{
		if (is_walkable(data, link->pos_x + 52, link->pos_y + 52))
			link->pos_x += M_S_LINK;
	}
	return (0);
}

int	monster_action(t_game *data, t_player *monster)
{
	if (monster->move_up)
	{
		if (is_walkable_m(data, monster->pos_x + 32, monster->pos_y + 15))
			monster->pos_y -= M_S_MONSTER;
	}
	else if (monster->move_down)
	{
		if (is_walkable_m(data, monster->pos_x + 30, monster->pos_y + 60))
			monster->pos_y += M_S_MONSTER;
	}
	else if (monster->move_left)
	{
		if (is_walkable_m(data, monster->pos_x + 15, monster->pos_y + 40))
			monster->pos_x -= M_S_MONSTER;
	}
	else if (monster->move_right)
	{
		if (is_walkable_m(data, monster->pos_x + 52, monster->pos_y + 52))
			monster->pos_x += M_S_MONSTER;
	}
	return (0);
}

int	get_last_direction(t_player *player1, t_player *player2)
{
	if (player1)
	{
		if (player1->move_up)
			return (MOVE_UP);
		else if (player1->move_down)
			return (MOVE_DOWN);
		else if (player1->move_left)
			return (MOVE_LEFT);
		else if (player1->move_right)
			return (MOVE_RIGHT);
		return (player1->last_direction);
	}
	if (player2)
	{
		if (player2->move_up)
			return (MOVE_UP_M);
		else if (player2->move_down)
			return (MOVE_DOWN_M);
		else if (player2->move_left)
			return (MOVE_LEFT_M);
		else if (player2->move_right)
			return (MOVE_RIGHT_M);
		return (player2->last_direction);
	}
	return (player2->last_direction);
}

void	update_player(t_game *data)
{
	t_player	*link;
	t_player	*monster;

	link = data->player[LINK];
	monster = data->player[MONSTER];
	draw_image_to_image(data->buffer, data->bg_img, 0, 0);
	if (link->anime_actived != -1)
	{
		update_animation(data, link);
	}
	else
		draw_image_to_image(data->buffer,
			data->pos_static[link->last_direction], link->pos_x, link->pos_y);
	if (monster->anime_actived != -1)
	{
		update_animation(data, monster);
	}
	else
		draw_image_to_image(data->buffer,
			data->pos_static[monster->last_direction], monster->pos_x,
			monster->pos_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buffer->img_ptr,
		0, 0);
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
