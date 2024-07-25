/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:11:12 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 20:29:19 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	this function loads an image from a file and stores it in the structure(t_img),
	and has all the parameters needed to manipulate the image.
*/
// return true on error
bool	load_image(t_game *data, t_img *img, const char *file)
{
	memset(img, 0, sizeof(*img));
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, (char *)file,
			&(img->width), &(img->height));
	if (img->img_ptr == NULL)
	{
		ft_putstr_fd("Error.\nFailed to load image : ", 2);
		ft_putstr_fd((char *)file, 2);
		return (true);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length,
			&img->endian);
	if (!img->addr)
	{
		ft_putstr_fd("Error.\nmlx_get_data in function load_image \
				failed\n", 2);
		return (true);
	}
	return (false);
}
