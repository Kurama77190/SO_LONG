/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_good_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 01:37:36 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/27 09:31:23 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_height(t_game *data, int height, int height_win);
int	check_map_width(t_game *data, int width, int width_win);

int	is_a_good_size(t_game *data)
{
	int	width;
	int	height;
	int	width_win;
	int	height_win;

	width = (data->map_width * 64);
	height = (data->map_height * 64);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_free_all(&data->memory_manager, data);
	}
	if (mlx_get_screen_size(data->mlx_ptr, &width_win, &height_win) == ERROR)
	{
		ft_putstr_fd("Error.\nLigne : 52 : MLX_GET_SCREEN ERROR.\n", 2);
		ft_free_all(&data->memory_manager, data);
	}
	check_map_width(data, width, width_win);
	check_map_height(data, height, height_win);
	mlx_destroy_display(data->mlx_ptr);
	ft_free(&data->mlx_ptr);
	return (SUCCESS);
}

int	check_map_height(t_game *data, int height, int height_win)
{
	if (height > height_win)
	{
		ft_putstr_fd("Error.\nthe height game is far too big, \
				reduce it.\n", 2);
		free_split(data->map);
		mlx_destroy_display(data->mlx_ptr);
		ft_free(&data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	return (SUCCESS);
}

int	check_map_width(t_game *data, int width, int width_win)
{
	if (width > width_win)
	{
		ft_putstr_fd("Error.\nthe width game is far too big, reduce it.\n", 2);
		free_split(data->map);
		mlx_destroy_display(data->mlx_ptr);
		ft_free(&data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	return (SUCCESS);
}
