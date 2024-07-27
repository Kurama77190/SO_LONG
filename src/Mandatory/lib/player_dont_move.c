/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dont_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 09:40:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/27 09:59:26 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	player_static(t_player *player)
{
	return (!(player->anime_actived == 1 || (player->move_up == 1 || player->move_down == 1 \
		|| player->move_left == 1 || player->move_right == 1)));
}
