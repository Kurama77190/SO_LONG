/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/06 18:30:47 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int key_hook(int keycode, t_game *data)
{
	(void)data;
	printf("%d\n", keycode);
	if (keycode ==  DIRECTION_UP)
	{
		printf("up");
	}
	return (0);
}

int	main(void)
{
	t_game	data;

	ft_init_game(&data);
	// printf("ptr : %p %p\n", data.win_ptr, data.mlx_ptr);
	// fflush(stdout);	
	mlx_key_hook(data.win_ptr,key_hook, &data);
	// printf("je suis apres mlx_key_hook\n");
	// fflush(stdout);
	mlx_loop(data.mlx_ptr);
	return (0);
}
