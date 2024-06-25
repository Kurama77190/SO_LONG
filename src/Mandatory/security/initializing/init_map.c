/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:22:02 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/25 20:38:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *data);

void	init_map(t_game *data)
{
	data->map = read_map(data, "/home/samy/42projet/SO_LONG/so_long", &data->map_width, &data->map_height);
	draw_map(data);
	// load all xpm for the map
	// afficher les img par apport a la map : 0 || 1 || c || 2 
}

void draw_element(t_game *data, t_img *element_img, int x, int y) {
    int i;
    int j;
    int color;

    j = 0;
    while (j < element_img->height) {
        i = 0;
        while (i < element_img->width) {
            color = *(int *)(element_img->addr + (j * element_img->line_length + i * (element_img->bpp / 8)));
            put_pixel_to_image(data->bg_img, x + i, y + j, color);
            i++;
        }
        j++;
    }
}
void	draw_map(t_game *data)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	data->bg_img->img_ptr = mlx_new_image(data->mlx_ptr, data->map_width * 32, data->map_height * 32);
	data->bg_img->addr = mlx_get_data_addr(data->bg_img->img_ptr, &data->bg_img->bpp, &data->bg_img->line_length, &data->bg_img->endian);

	while (y < data->map_height)
	{
		while (x < data->map_width)
		{
			if (data->map[i][j] == '0')
				draw_element(data, data->pos_static[0], x * 32, y * 32);
				// draw_image_with_transparency(data, data->pos_static[0], x * 32, y * 32);
			else if (data->map[i][j] == '1')
				draw_element(data, data->pos_static[1], x * 32, y * 32);
				// draw_image_with_transparency(data, data->pos_static[1], x * 32, y * 32);
			else if (data->map[i][j] == 'C')
				draw_element(data, data->pos_static[2], x * 32, y * 32);
				// draw_image_with_transparency(data, data->pos_static[2], x * 32, y * 32);
			else if (data->map[i][j] == '2')
				draw_element(data, data->pos_static[3], x * 32, y * 32);
				// draw_image_with_transparency(data, data->pos_static[3], x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
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

