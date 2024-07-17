/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:21:01 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/17 17:24:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_img(t_img **img, void *mlx_ptr)
{
	if (img && *img)
	{
		if ((*img)->img_ptr)
		{
			mlx_destroy_image(mlx_ptr, (*img)->img_ptr);
			(*img)->img_ptr = NULL;
		}
		ft_free((void **)img);
	}
	return ;
}
