/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 01:37:51 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/09 23:03:48 by sben-tay         ###   ########.fr       */
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
#include <string.h>

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    int     img_width;
    int     img_height;
} t_data;

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "src/Mandatory/img/zelda.xpm", &data.img_width, &data.img_height);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.img_width, data.img_height, "The Legend Of Zelda: A link to MLX");
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
}
