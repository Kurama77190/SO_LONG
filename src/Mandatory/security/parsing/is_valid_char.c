/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:33:47 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/22 23:49:42 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_valid_char(int *array);

int	is_valid_char(char **map)
{
	static int	validchar[128] = {false};
	int			i;
	int			j;

	i = 0;
	set_valid_char(validchar);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(validchar[(size_t)map[i][j]]))
			{
				free_split(map);
				ft_putstr_fd("Your map have invalid char.\n", 2);
				exit(EXIT_FAILURE);
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

void	set_valid_char(int *array)
{
	array[(size_t) 'M'] = true;
	array[(size_t) 'P'] = true;
	array[(size_t) 'C'] = true;
	array[(size_t) 'E'] = true;
	array[(size_t) '0'] = true;
	array[(size_t) '1'] = true;
	array[(size_t) '\n'] = true;
}
