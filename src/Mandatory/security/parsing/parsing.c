/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:55 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 02:18:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		flood_fill(char **map);

int		is_a_good_size(t_game *data);

void	parsing(t_game *data)
{
	is_a_valid_ber(data->n_map);
	data->map = read_map(data, data->n_map, &data->map_width, \
			&data->map_height);
	is_a_good_size(data);
	is_rectangle(data->map);
	is_valid_char(data->map);
	is_double(data->map);
	is_map_close(data->map);
	flood_fill(data->map);
}
