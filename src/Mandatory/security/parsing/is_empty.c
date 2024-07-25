/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:00:29 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 21:03:53 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_empty(t_game *data)
{
	int		fd;
	char	*res;

	fd = open(data->n_map, O_RDONLY);
	if (!fd)
	{
		perror("Error.\n");
		exit(EXIT_FAILURE);
	}
	res = get_next_line(fd);
	if (!res)
	{
		ft_putstr_fd("Error.\nYour map is empty.\n", 2);
		ft_free((void **)&res);
		close(fd);
		exit(EXIT_FAILURE);
	}
	ft_free((void **)&res);
	close(fd);
	return (SUCCESS);
}
