/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_with_transparency.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:14:40 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/03 13:00:36 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//	this function draws an image with transparency on the window.
//	0x489848 is the color that will be transparent.

void	draw_image_with_transparency(t_game *data, t_img *img, int pos_x, \
		int pos_y)
{
	int	y;
	int	x;
	int	pixel;
	int	trans_color;

	trans_color = 0x489848;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = *(int *)(img->addr + y * img->line_length + x * (img->bpp
						/ 8));
			if (pixel != trans_color)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos_x + x, pos_y
					+ y, pixel);
			x++;
		}
		y++;
	}
}
