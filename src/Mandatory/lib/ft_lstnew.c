/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:09:56 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/18 03:41:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_new_img(t_img *data);
static void	load_image(t_game *data, t_img *img, const char *file);


t_frame	*ft_lstnew(const char *content, t_game *data)
{
	t_frame	*new;

	new = ft_malloc(data->memory_manager, sizeof(t_frame));
	new->img = ft_malloc(data->memory_manager, sizeof(t_img));
    load_image(data, new->img, content);
	new->next = NULL;
	return (new);
}

static void	load_image(t_game *data, t_img *img, const char *file)
{
	ft_init_new_img(img);
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, (char *)file, &img->width, &img->height);
	if (img->img_ptr == NULL)
	{
		fprintf(stderr, "Failed to load image: %s\n", file);
		ft_free_all(&data->memory_manager);
		exit(2);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length,
			&img->endian);
}

static void	ft_init_new_img(t_img *data)
{
	data->img_ptr = NULL;
	data->addr = NULL;
	data->width = 0;
	data->height = 0;
	data->bpp = 0;
	data->line_length = 0;
	data->endian = 0;	
}
