/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:00:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/23 01:18:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		count_paths(const char *paths[]);

void	load_animation(t_game *data, e_AnimationType action,
		const char *paths[])
{
	int	i;
	int	j;

	if (!data)
	{
		perror("Error init \n");
		ft_free_all(&data->memory_manager, data);
		exit(1);
	}
	i = -1;
	j = count_paths(paths);
	data->animations[action] = ft_calloc(1, sizeof(t_animation),
			&data->memory_manager, "ANIMATION");
	while (++i < j)
	{
		ft_lstadd_back(&(data->animations[action]->frames), ft_lstnew(paths[i],
				data));
		if (i == 0)
		{
			data->animations[action]->current = data->animations[action]->frames;
			data->animations[action]->frame_count = 0;
		}
	}
	return ;
}

int	count_paths(const char *paths[])
{
	int	i;

	i = 0;
	while (paths[i])
		i++;
	return (i);
}
