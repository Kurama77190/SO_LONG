/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:12:36 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/27 09:38:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_secure(char **map);

int	is_map_close(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (map[x])
		x++;
	while (map[i][j] && map[i][j] != '\n')
	{
		if (map[i][j] != '1' && map[i][j] != '\n')
			exit_secure(map);
		if (map[x - 1][j] != '1' && map[x - 1][j] != '\n')
			exit_secure(map);
		j++;
	}
	j = 1;
	while (map[i])
	{
		if (map[i][0] != '1' || (map[i][ft_strlen_gnl(map[i]) - 1] != '1'))
			exit_secure(map);
		i++;
	}
	return (SUCCESS);
}

void	exit_secure(char **map)
{
	ft_putstr_fd("Error.\nYour map is not closed. \
		Please check your file.\n", 2);
	free_split(map);
	exit(EXIT_FAILURE);
}
