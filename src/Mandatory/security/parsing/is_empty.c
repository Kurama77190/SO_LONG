/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:00:29 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 23:10:38 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_empty(t_game *data)
{
	if (data->map_width == 0 || data->map_height == 0)
	{
		free_split(data->map);
		ft_putstr_fd("Error.\nYour map is empty.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (SUCCESS);
}
