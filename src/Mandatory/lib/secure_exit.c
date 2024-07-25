/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:05:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 02:11:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	secure_exit(t_game *data)
{
	if (!data)
	{
		ft_free_all(&data->memory_manager, data);
	}
	ft_putstr_fd("Failed to load background image\n", 2);
	ft_free_all(&data->memory_manager, data);
}
