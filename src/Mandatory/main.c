/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/08 15:47:57 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	update_background(t_game *data);

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_game	data;
	
	data.n_map = argv[1];
	ft_init_game(&data);

	// Utiliser mlx_hook pour capturer les événements de touche enfoncée et relâchée
	
	mlx_hook(data.win_ptr, 2, 1L << 0, keypress_hook, &data);
	mlx_hook(data.win_ptr, 3, 1L << 1, keyrelease_hook, &data);

	// Utiliser mlx_loop_hook pour mettre à jour l'animation
	
	mlx_loop_hook(data.mlx_ptr, update_game, &data); // a décommenter pour activer l'animation fluide

	// Démarrer la boucle principale de MLX

	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.bg_img->img_ptr);
	ft_free(data.bg_img);
	mlx_destroy_image(data.mlx_ptr, data.buffer->img_ptr);
    ft_free(data.buffer);

	return (0);
}

// 8.158

/*
	TODO: RANGER INIT_KEYS ET LE MAIN
	FIXME: OK

	TODO: FAIRE UN MONSTRE EN RAPIDUS RAPIDUS !
	FIXME: ok

	TODO: TUER LINK
	FIXME: 

	TODO: FAIRE LE PARSING
	FIXME:

	TODO: NORMALISER TOUS LES FICHIERS DU PROJETS... GOOD LUCK ☺
	FIXME:

	TODO: TROP DE FONCTION DANS UPDATE.C
	FIXME:

	TODO: PUSH CE PROJET ET EVITEZ LE BLAKCHOLE ZEBI !
	FIXME:

*/

// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠈⢆⠀⠀⠀⠈⣹⣷⣀⣴⠀⢠⣤⣶⡦⠀⠀⠀⠀⠀⠀
// ⠢⣀⠀⠀⠀⠀⠀⢄⠀⠈⣆⣠⣼⣿⣿⣿⣿⣿⣦⣼⣏⡀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠈⠻⣶⣄⡀⠀⣨⣷⡿⠟⠋⠉⠉⠉⠉⠛⠿⣿⣿⣿⣧⣀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠙⢿⣿⡿⠋⠀⠀⠀⠀⢠⡄⠀⠀⠀⠈⠙⣿⣿⣏⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⣠⣿⣿⣆⠀⠀⠀⠀⠈⣿⣿⡁⠀⠀⠀⠀⠀
// ⠀⠀⠀⠒⢺⣿⠁⠀⠀⠀⠀⡰⠿⠿⠿⠿⢆⠀⠀⠀⠀⠸⣿⡿⠃⠀⠀⠀⠀
// ⠀⠀⠀⢠⣾⣿⠀⠀⠀⠀⣴⣷⡀⠀⠀⢀⣼⣦⠀⠀⠀⠀⣿⣿⠆⠀⠀⠀⠀
// ⠀⠀⠀⠀⣹⣿⠀⠀⠀⣼⣿⣿⣷⡀⢀⣾⣿⣿⣧⡀⠀⢠⣿⡧⠤⠀⠀⠀⠀
// ⠀⠀⠀⠈⠛⢿⣆⠀⠈⠉⠉⠉⠉⠉⠈⠉⠉⠉⠉⠁⠀⣼⡿⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠻⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣷⣄⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠚⢻⣿⣿⣦⣄⡀⠀⠀⠀⠀⢀⣠⣶⣿⡋⠀⠈⠙⠻⣦⡀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⢙⣿⠿⢿⣿⣿⣿⣿⣿⠛⠙⡁⠀⠁⠀⠀⠀⠀⠀⠉⠂⠄
// ⠀⠀⠀⠀⠀⠰⣶⡾⠿⠀⠸⠋⠻⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//		© 2024 - sben-tay - 42 PARIS
