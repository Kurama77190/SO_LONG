/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_step_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 06:14:09 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 21:06:04 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_step_count(t_game *data)
{
	char	*step_char;

	step_char = ft_itoa(data->step_counter);
	if (!step_char)
		ft_free_all(&data->memory_manager, data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 24, 24, 0xFFFFFF, step_char);
	free(step_char);
	return (SUCCESS);
}

void	update_step_count_terminal(t_game *data)
{
	ft_putstr_fd(ft_itoa(data->step_counter), 1);
	ft_putstr_fd("\n", 1);
}
