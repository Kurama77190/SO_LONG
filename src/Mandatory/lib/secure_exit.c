/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:05:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 01:48:15 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	secure_exit(t_game *data)
{
	if(!data)
	{
		perror("Error_secure_exit\n");
		ft_free_all(&data->memory_manager, data);
	}
	perror("Failed to load background image\n");
	ft_free_all(&data->memory_manager, data);
	exit(EXIT_FAILURE);
}
