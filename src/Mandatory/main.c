/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/09 23:03:58 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }

void testing(t_game *data);

int main(void)
{
	t_game data;

	data.memory_manager = NULL;
	char **test = ft_split("Salut je suis un roi\n", ' ', &data.memory_manager, "ROI");
	while (*test)
	{
		printf("%s ", *test);
		test++;
	}

	printf("\n");
	testing(&data);
	ft_free_all(&data.memory_manager);
}

void testing(t_game *data)
{
	char *teste = ft_calloc(10, sizeof(char), data->memory_manager, "REINE");
	teste = "42_PARIS";

	printf("%s\n", teste);
}
