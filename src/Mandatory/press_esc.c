/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_esc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 06:58:27 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 06:58:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_esc(t_game *data, int keycode)
{
	if (keycode == KEY_ESC)
	{
		ft_free_all(&data->memory_manager, data);
	}
}
