/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:42:20 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/22 18:42:41 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


bool find_double(int player, int monster, int exit_, char **map);

int	is_double(char **map)
{
	int	player;
	int	monster;
	int	exit_;

	player = 0;
	monster = 0;
	exit_ = 0;
	if (find_double(player, monster, exit_, map))
	{
		free_split(map);
		ft_putstr_fd("Your map have double. Please check your file\n", 2);
		exit(EXIT_FAILURE);
		return (ERROR);
	}
	return (SUCCESS);
}

bool find_double(int player, int monster, int exit_, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'M')
				monster++;
			if (map[i][j] == 'E')
				exit_++;
			j++;
		}
		if (player > 1 || monster > 1 || exit_ > 1)
		{
			return (true);
		}
		i++;
	}
	return (false);
}
