/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 01:37:51 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/08 02:20:27 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/08 01:36:38 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		height;
	int		width;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1600, 800, "THE LEGEND OF ZELDA: A LINK TO MLX");
	img.img = mlx_new_image(mlx, 1600, 800);
	img.img = mlx_xpm_file_to_image(mlx, "src/Mandatory/img/zelda.xpm", &height, &width);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
