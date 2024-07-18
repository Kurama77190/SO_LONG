/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:09:56 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/18 17:48:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_game *data, t_img *img, const char *file);

t_frame	*ft_lstnew(const char *content, t_game *data)
{
	t_frame	*new;

	new = malloc(sizeof(t_frame));
	if (!new)
	{
		return (NULL);
	}
	new->img = malloc(sizeof(t_img));
	if (!new->img)
	{
		return (NULL);
	}
	fprintf(stderr, "load image: %s\n", content);
	load_image(data, new->img, content);
	new->next = NULL;
	return (new);
}

void	load_image(t_game *data, t_img *img, const char *file)
{
	if (!img)
	{
		fprintf(stderr, "ERRROR : msg is NULL");
	}
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, (char *)file,
			&(img->width), &(img->height));
	if (img->img_ptr == NULL)
	{
		fprintf(stderr, "Failed to load image: %s\n", file);
		ft_free_all(&data->memory_manager, data);
		exit(2);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length,
			&img->endian);
}
