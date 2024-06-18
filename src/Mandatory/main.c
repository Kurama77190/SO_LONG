/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/19 00:35:36 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>


int main(void)
{
    t_game data;

    ft_init_game(&data);

    // Utiliser mlx_hook pour capturer les événements de touche enfoncée et relâchée
    mlx_hook(data.win_ptr, 2, 1L<<0, keypress_hook, &data);
    mlx_hook(data.win_ptr, 3, 1L<<1, keyrelease_hook, &data);

    // Utiliser mlx_loop_hook pour mettre à jour l'animation
    mlx_loop_hook(data.mlx_ptr, update_animation, &data);

    // Démarrer la boucle principale de MLX
    mlx_loop(data.mlx_ptr);
    return (0);
}
