/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:55 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/23 14:23:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char **map);
int	is_map_close(char **map);

void	parsing(t_game *data)
{
	data->map = read_map(data, data->n_map, &data->map_width, \
	 &data->map_height);
	
	// TODO: elle doit etre de forme rectangulaire.
	is_rectangle(data->map);
	// TODO: la carte doit contenir 1 sortie, 1 colectible, et 1 position de depart.
	is_valid_char(data->map);
	// TODO: Si la maps contiens des doublons sauf item exit_failure.
	is_double(data->map);
	// TODO: La carte doit etre fermer encadrer par des mures.
	is_map_close(data->map);
	// TODO: checker si il y a un chemin valide qu il est possible d emprunter dans la carte.
		
	// 
}
void	exit_secure(char **map);

int	is_map_close(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	printf("1\n");
	while (map[x])
		x++;
	printf("2\n");
	while(map[i][j] && map[i][j] != '\n')
	{
		// printf("%s\n", map[i]);
		if (map[i][j] != '1' && map[i][j] != '\n')
			exit_secure(map);
		if (map[x - 1][j] != '1' && map[x - 1][j] != '\n')
			exit_secure(map);
		j++;
	}
	j = 1;
	printf("3\n");
	while(map[i])
	{
		printf("%d\n", ft_strlen(map[i]));
		if (map[i][0] != '1' || (map[i][ft_strlen_gnl(map[i]) - 1] != '1'))
			exit_secure(map);
		i++;
	}
	return (SUCCESS);
}



void	exit_secure(char **map)
{
	ft_putstr_fd("Your map is not closed. Please check your file.\n", 2);
	free_split(map);
	exit(EXIT_FAILURE);	
}