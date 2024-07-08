/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:00:02 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/08 18:55:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_animation(t_game *data, t_player *player)
{
	int			usleep;
	t_animation	*animation;
	t_frame		*current;

	if (player == data->player[LINK])
		usleep = 4;
	else
		usleep = 10;
	animation = data->animations[player->last_direction];
	current = animation->current;
	if (current != NULL)
	{
		draw_animation_frame(data, animation, player->pos_x, player->pos_y);
		if (animation->frame_count % usleep == 0)
		{
			animation->current = current->next;
			data->step_counter++;
		}
		if (animation->current == NULL)
			animation->current = animation->frames;
		animation->frame_count++;
	}
	return (0);
}
