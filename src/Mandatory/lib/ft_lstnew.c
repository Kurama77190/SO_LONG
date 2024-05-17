/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:09:56 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/17 18:31:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_img *img, void *mlx_ptr, const char *file);

t_frame	*ft_lstnew(const char *content, t_game *data)
{
	t_frame	*new;

	new = malloc(sizeof(t_frame));
	if (!new)
		return (NULL);
	new->img->img_ptr = mlx_new_image(data->mlx_ptr, 66, 72);
    load_image(new->img, data->mlx_ptr, content);
	new->next = NULL;
	return (new);
}

void	load_image(t_img *img, void *mlx_ptr, const char *file)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, (char *)file, &img->width,
			&img->height);
	if (!img->img_ptr)
	{
		fprintf(stderr, "Failed to load image: %s\n", file);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length,
			&img->endian);
}