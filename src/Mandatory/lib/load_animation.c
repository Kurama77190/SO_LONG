/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:00:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/04 12:53:42 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_animation(t_game *data, e_AnimationType action, \
		const char *paths[])
{
	int	i;

	if (!data)
	{
		printf("Error init \n");
		exit(1);
	}
	i = -1;
	data->animations[action] = ft_calloc(1, sizeof(t_animation), \
			data->memory_manager, "ANIMATION");
	while (++i < 10)
	{
		ft_lstadd_back(&(data->animations[action]->frames), ft_lstnew(paths[i], \
				data));
		printf("numero FRAMES = %i\n", i);
		if (i == 0)
		{
			data->animations[action]->current = data->animations[action]->frames;
			data->animations[action]->frame_count = 0;
		}
	}
	return ;
}
