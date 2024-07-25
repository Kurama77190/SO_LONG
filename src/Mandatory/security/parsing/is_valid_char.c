/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:33:47 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 20:30:53 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_char(int *array, char **map, int i, int j);
int	check_main_char(int *array, char **map, int i, int j);

int	is_valid_char(char **map)
{
	static int	validchar[128] = {false};
	static int	mainchar[128] = {false};
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (check_valid_char(validchar, map, i, j) == ERROR)
	{
		free_split(map);
		ft_putstr_fd("Error.\nYour map have invalid char.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (check_main_char(mainchar, map, i, j) == ERROR)
	{
		free_split(map);
		ft_putstr_fd("Error.\nYour map doesn't have all valid char.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (SUCCESS);
}

int	check_main_char(int *array, char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == 'C')
			{
				array[(size_t)map[i][j]] = true;
			}
			j++;
		}
		i++;
	}
	if (array[('E')] == false)
		return (ERROR);
	if (array['C'] == false)
		return (ERROR);
	if (array['P'] == false)
		return (ERROR);
	return (SUCCESS);
}

int	check_valid_char(int *array, char **map, int i, int j)
{
	array['M'] = true;
	array['P'] = true;
	array['C'] = true;
	array['E'] = true;
	array['0'] = true;
	array['1'] = true;
	array['\n'] = true;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(array[(size_t)map[i][j]]))
			{
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
