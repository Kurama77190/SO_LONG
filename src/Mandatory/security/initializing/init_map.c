/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:22:02 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/02 08:35:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *data);

void	init_map(t_game *data)
{
	data->map = read_map(data, data->n_map, &data->map_width, &data->map_height);
	printf("width = %d\n", data->map_width);
	printf("height = %d\n", data->map_height);
	draw_map(data);
	// load all xpm for the map
	// afficher les img par apport a la map : 0 || 1 || c || 2 
}

void draw_element(t_game *data, t_img *element_img, int x, int y)
{
    int i;
    int j;
    int color;

    j = 0;
	if (element_img ->img_ptr)
	{
		while (j < element_img->height)
		{
			i = 0;
			while (i < element_img->width)
			{
				color = *(int *)(element_img->addr + (j * element_img->line_length + i * (element_img->bpp / 8)));
				if (!(color == 0x489848))
					put_pixel_to_image(data->bg_img, x + i, y + j, color);
				i++;
			}
			j++;
		}
	}
}


void	draw_map(t_game *data)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	data->bg_img->img_ptr = mlx_new_image(data->mlx_ptr, data->map_width * 64, data->map_height * 64);
	if (data->bg_img->img_ptr == NULL)
	{
		fprintf(stderr, "Failed to load background image\n");
		ft_free_all(&data->memory_manager);
		exit(2);
	}
	data->bg_img->addr = mlx_get_data_addr(data->bg_img->img_ptr, &data->bg_img->bpp, &data->bg_img->line_length, &data->bg_img->endian);

	while (y < data->map_height)
	{
		while (x < data->map_width && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == '0')
				draw_element(data, data->assets[FLOOR], x * 64, y * 64);
			else if (data->map[i][j] == '1')
				draw_element(data, data->assets[WALL], x * 64, y * 64);
			else if (data->map[i][j] =='E')
			{
				draw_element(data, data->assets[FLOOR], x * 64, y * 64);
				data->pos_char_x = x * 64;
				data->pos_char_y = y * 64;
			}
			x++;
			j++;
		}
		x = 0;
		j = 0;
		i++;
		y++;
	}
	printf("jai buffer la maps\n");
	printf("pos_char_x = %d\n", data->pos_char_x);
	printf("pos_char_y = %d\n", data->pos_char_y);
}

// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠈⢆⠀⠀⠀⠈⣹⣷⣀⣴⠀⢠⣤⣶⡦⠀⠀⠀⠀⠀⠀
// ⠢⣀⠀⠀⠀⠀⠀⢄⠀⠈⣆⣠⣼⣿⣿⣿⣿⣿⣦⣼⣏⡀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠈⠻⣶⣄⡀⠀⣨⣷⡿⠟⠋⠉⠉⠉⠉⠛⠿⣿⣿⣿⣧⣀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠙⢿⣿⡿⠋⠀⠀⠀⠀⢠⡄⠀⠀⠀⠈⠙⣿⣿⣏⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⣠⣿⣿⣆⠀⠀⠀⠀⠈⣿⣿⡁⠀⠀⠀⠀⠀
// ⠀⠀⠀⠒⢺⣿⠁⠀⠀⠀⠀⡰⠿⠿⠿⠿⢆⠀⠀⠀⠀⠸⣿⡿⠃⠀⠀⠀⠀
// ⠀⠀⠀⢠⣾⣿⠀⠀⠀⠀⣴⣷⡀⠀⠀⢀⣼⣦⠀⠀⠀⠀⣿⣿⠆⠀⠀⠀⠀
// ⠀⠀⠀⠀⣹⣿⠀⠀⠀⣼⣿⣿⣷⡀⢀⣾⣿⣿⣧⡀⠀⢠⣿⡧⠤⠀⠀⠀⠀
// ⠀⠀⠀⠈⠛⢿⣆⠀⠈⠉⠉⠉⠉⠉⠈⠉⠉⠉⠉⠁⠀⣼⡿⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠻⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣷⣄⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠚⢻⣿⣿⣦⣄⡀⠀⠀⠀⠀⢀⣠⣶⣿⡋⠀⠈⠙⠻⣦⡀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⢙⣿⠿⢿⣿⣿⣿⣿⣿⠛⠙⡁⠀⠁⠀⠀⠀⠀⠀⠉⠂⠄
// ⠀⠀⠀⠀⠀⠰⣶⡾⠿⠀⠸⠋⠻⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//		© 2024 - sben-tay - 42 PARIS

