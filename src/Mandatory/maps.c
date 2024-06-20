/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:45:21 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/20 02:22:00 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// a finir de coder

int	count_lines(const char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

// Fonction pour lire la carte du fichier
char	**read_map(t_game *data, const char *filename, int *width, int *height)
{
	int		lines;
	char	**map;
	int		fd;
	char	*line;
	int		i;

	lines = count_lines(filename);
	map = (char **)ft_calloc(lines + 1, sizeof(char *), data->memory_manager,
			NULL);
	if (!map)
	{
		perror("Failed to allocate memory for map");
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	*height = lines;
	*width = ft_strlen(map[0]);
	return (map);
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_image_to_image(t_img *dest_img, t_img *src_img, int x, int y)
{
	int	color;

	int src_x, src_y;
	src_y = 0;
	while (src_y < src_img->height)
	{
		src_x = 0;
		while (src_x < src_img->width)
		{
			color = *(unsigned int *)(src_img->addr + src_y
					* src_img->line_length + src_x * (src_img->bpp / 8));
			if (color != 0x000000)
			{
				put_pixel_to_image(dest_img, x + src_x, y + src_y, color);
			}
			src_x++;
		}
		src_y++;
	}
}

void	create_map_image(t_game *data)
{
	char	tile;

	int x, y;
	data->bg_img->img_ptr = mlx_new_image(data->mlx_ptr, data->map_width
			* data->wall_img->width, data->map_height * data->wall_img->height);
	data->bg_img->addr = mlx_get_data_addr(data->bg_img->img_ptr,
			&data->bg_img->bpp, &data->bg_img->line_length,
			&data->bg_img->endian);
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			tile = data->map[y][x];
			if (tile == '1')
				draw_image_to_image(&data->bg_img, &data->wall_img, x
					* data->wall_img.width, y * data->wall_img.height);
			else if (tile == '0')
				draw_image_to_image(&data->bg_img, &data->floor_img, x
					* data->floor_img.width, y * data->floor_img.height);
			else if (tile == 'P')
				draw_image_to_image(&data->bg_img, &data->player_img, x
					* data->player_img.width, y * data->player_img.height);
			// Add other cases as needed for other elements like collectibles,
			enemies, etc.x++;
		}
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

