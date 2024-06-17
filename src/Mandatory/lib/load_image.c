/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:11:12 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/17 06:05:46 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	this function loads an image from a file and stores it in the structure(t_img), 
	and has all the parameters needed to manipulate the image.
*/


void	load_image(t_game *data, t_img *img, const char *file)
{
	if (!img)
	{
		printf("Error: img is NULL\n");
		exit(2);
	}
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, (char *)file, &(img->width), &(img->height));
	if (img->img_ptr == NULL)
	{
		fprintf(stderr, "Failed to load image: %s\n", file);
		ft_free_all(&data->memory_manager);
		exit(2);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length,
			&img->endian);
}
