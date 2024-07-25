/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:09:56 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/25 18:59:35 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		free(new);
		return (NULL);
	}
	new->next = NULL;
	if (load_image(data, new->img, content))
	{
		ft_free((void **)&new->img);
		ft_free((void **)&new);
		ft_free_all(&data->memory_manager, data);
	}
	return (new);
}
