/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/19 15:57:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	loop_animation(t_game *data);

int	main(void)
{
	t_game	data;

	ft_init_game(&data);
	loop_animation(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

void	loop_animation(t_game *data)
{
	t_frame 	*current;
	int			i;

	current = data->animations[MOVE_DOWN]->frames;
	printf("ptr_mlx = %p\n", data->mlx_ptr);
	while (1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, current->img->img_ptr, 0, 0);
		usleep(100000);
		if (i == 50)
			current = data->animations[MOVE_LEFT]->frames;
		if (i == 100)
			current = data->animations[MOVE_RIGHT]->frames;
		if (i == 150)
			current = data->animations[MOVE_UP]->frames;
		if (!current->next && i < 50)
			current = data->animations[MOVE_DOWN]->frames;
		if (!current->next && i > 50 && i < 100)
			current = data->animations[MOVE_LEFT]->frames;
		current = current->next;
		if (!current->next && i > 100 && i < 150)
			current = data->animations[MOVE_RIGHT]->frames; 
		if (!current->next && i > 150 && i < 200)
			current = data->animations[MOVE_UP]->frames;
		if (i == 200)
			i = 0;
		i++;
	}
}


// void	ft_init_animation(t_game *data)
// {
// 	int	i;

// 	if (!data)
// 	{
// 		printf("Error init \n");
// 		exit(1);
// 	}
// 	data->mlx_ptr = mlx_init();
// 	printf("ptr_mlx = %p\n", data->mlx_ptr);
// 	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 800, "so_long");
// 	i = -1;
// 	data->animations[MOVE_DOWN] = ft_calloc(1, sizeof(t_animation), data->memory_manager, NULL);
// 	while (i++ < 9)
// 	{
// 		ft_lstadd_back(&(data->animations[MOVE_DOWN]->frames), ft_lstnew(g_x_move_down[i], data));
// 	}
// 	while(1)
// 	{
// 		t_frame *current = data->animations[MOVE_DOWN]->frames;

// 		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, current->img->img_ptr, 0, 0);
// 		current = current->next;
// 		if (current->next == NULL)
// 		{
// 			current = data->animations[MOVE_DOWN]->frames;
// 		}
// 		mlx_do_sync(data->mlx_ptr);
// 		usleep(100000);
	
// 	}
// 	mlx_loop(data->mlx_ptr);	
// 	return ;
// }








// static void	load_image(t_game *data, t_img *img, void *mlx_ptr, const char *file);

// int main(void)
// {
// 	t_game data;

// 	data.mlx_ptr = mlx_init();
// 	printf("ptr_mlx = %p\n", data.mlx_ptr);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "so_long");
// 	data.animations[MOVE_DOWN] = ft_malloc(data.memory_manager, sizeof(t_animation));
// 	data.animations[MOVE_DOWN]->frames = ft_malloc(data.memory_manager, sizeof(t_frame));
// 	data.animations[MOVE_DOWN]->frames->img = ft_malloc(data.memory_manager, sizeof(t_img));
// 	printf("ptr_mlx = %p\n", data.mlx_ptr);
// 	load_image(&data, data.animations[MOVE_DOWN]->frames->img, data.mlx_ptr, g_x_move_down[0]);
// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.animations[MOVE_DOWN]->frames->img->img_ptr, 0, 0);
// 	mlx_loop(data.mlx_ptr);
// }

// static void	load_image(t_game *data, t_img *img, void *mlx_ptr, const char *file)
// {
// 	printf("file: %s\n", file);
// 	printf("data->mlx_ptr: %p\n", mlx_ptr);
// 	printf("img->img_ptr: %p\n", img->img_ptr);
// 	printf("img->width: %d\n", img->width);
// 	printf("img->height: %d\n", img->height);
// 	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, (char *)file, &img->width,
// 			&img->height);
// 	if (!img->img_ptr)
// 	{
// 		fprintf(stderr, "Failed to load image: %s\n", file);
// 		ft_free_all(&data->memory_manager);
// 		exit(2);
// 	}
// 	printf("file: %s\n", file);
// 	printf("data->mlx_ptr: %p\n", mlx_ptr);
// 	printf("img->img_ptr: %p\n", img->img_ptr);
// 	printf("img->width: %d\n", img->width);
// 	printf("img->height: %d\n", img->height);
// 	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length,
// 			&img->endian);
// }






























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
