/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/18 03:37:00 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

static const char	*g_x_move_down[10] = {
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_1.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_2.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_3.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_4.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_5.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_6.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_7.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_8.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_9.xpm",
	"src/Mandatory/img/sheetsprite/down/XPM/link_move_down_10.xpm"};

// static void	load_image(t_game *data, t_img *img, void *mlx_ptr, const char *file);

// int main(void)
// {
// 	t_game data;

// 	data.mlx_ptr = mlx_init();
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "so_long");
// 	data.animations[MOVE_DOWN] = ft_malloc(data.memory_manager, sizeof(t_animation));
// 	load_image(&data, &data.animations[MOVE_DOWN]->frames.img, data.mlx_ptr, g_x_move_down[0]);
// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.animations[MOVE_DOWN]->frames.img.img_ptr, 0, 0);
// 	mlx_loop(data.mlx_ptr);
// }

// static void	load_image(t_game *data, t_img *img, void *mlx_ptr, const char *file)
// {
// 	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, (char *)file, &img->width,
// 			&img->height);
// 	if (!img->img_ptr)
// 	{
// 		fprintf(stderr, "Failed to load image: %s\n", file);
// 		ft_free_all(&data->memory_manager);
// 		exit(2);
// 	}
// 	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length,
// 			&img->endian);
// }



void	ft_init_animation(t_game *data);

int	main(void)
{
	t_game	data;

	ft_init_animation(&data);
	return (0);
}

void	ft_init_animation(t_game *data)
{
	int	i;

	if (!data)
	{
		printf("Error init \n");
		exit(1);
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 800, "so_long");
	i = 0;
	data->animations[MOVE_DOWN] = ft_malloc(data->memory_manager, sizeof(t_animation));
	data->animations[MOVE_DOWN]->frames = ft_lstnew(g_x_move_down[i], data);
	i++;
		while (i++ < 10)
		{
			ft_lstadd_back(&(data->animations[MOVE_DOWN]->frames), ft_lstnew(g_x_move_down[i], data));
			i++;
		}
	i = 0;
	return ;
}





























// void testing(t_game *data);

// int main(void)
// {
// 	t_game data;

// 	data.memory_manager = NULL;
// 	char **test = ft_split("Salut je suis un roi\n", ' ', &data.memory_manager,
			// "ROI");
// 	while (*test)
// 	{
// 		printf("%s ", *test);
// 		test++;
// 	}

// 	printf("\n");
// 	testing(&data);
// 	ft_free_all(&data.memory_manager);
// }

// void testing(t_game *data)
// {
// 	char *teste = ft_calloc(10, sizeof(char), data->memory_manager, "REINE");
// 	teste = "42_PARIS";

// 	printf("%s\n", teste);
// }
