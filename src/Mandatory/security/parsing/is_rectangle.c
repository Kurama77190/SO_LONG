/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:45:16 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/22 18:45:29 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	int	i;
	int	len_line;

	i = 1;
	len_line = ft_strlen_gnl(map[0]);
	while(map[i])
	{
		if ((ft_strlen_gnl(map[i])) != len_line)
		{
			ft_putstr_fd("Your map is not a rectangle\n", 2);
			free_split(map);
			exit(EXIT_FAILURE);
			return (ERROR);
		}
		else
			i++;
	}
	return (SUCCESS);
}
