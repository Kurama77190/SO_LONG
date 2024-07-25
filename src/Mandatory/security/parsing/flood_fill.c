/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:13:28 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/24 23:49:13 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_duplicate(char **map);
int		start_on_player(char **map, t_flood_fill *data);
bool	replace_with_star(char **map, int x, int y, t_flood_fill *data);
int		init_flood_fill(t_flood_fill *data, char **map);

int	flood_fill(char **map)
{
	char			**map_cpy;
	t_flood_fill	data;
	int				i;

	init_flood_fill(&data, map);
	map_cpy = map_duplicate(map);
	start_on_player(map_cpy, &data);
	if ((data.nb_coin != data.coin_max) || data.exit == false)
	{
		ft_putstr_fd("FLood fill invalid, please check your file.\n", 2);
		i = 0;
		while (map_cpy[i])
		{
			printf("%s", map_cpy[i]);
			i++;
		}
		free_split(map_cpy);
		free_split(map);
		exit(EXIT_FAILURE);
	}
	free_split(map_cpy);
	return (SUCCESS);
}

int	init_flood_fill(t_flood_fill *data, char **map)
{
	data->coin_max = count_char(map, 'C');
	data->nb_coin = 0;
	data->exit = false;
	return (SUCCESS);
}

int	start_on_player(char **map, t_flood_fill *data)
{
	bool	is_player;
	int		x;
	int		y;

	is_player = false;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				is_player = true;
				break ;
			}
			y++;
		}
		if (is_player)
			break ;
		x++;
	}
	if (replace_with_star(map, x, y, data))
		return (SUCCESS);
	return (ERROR);
}

// BACK_UP SAFE !!!//

bool	replace_with_star(char **map, int x, int y, t_flood_fill *data)
{
	int	res;

	res = 0;
	if (map[x][y] == '1' || map[x][y] == '*')
		return (0);
	else if (map[x][y] == 'C')
		data->nb_coin += 1;
	else if (map[x][y] == 'E')
		data->exit = true;
	if (map[x][y] == '0' || map[x][y] == 'E' || map[x][y] == 'C')
		map[x][y] = '*';
	if (data->nb_coin >= data->coin_max && data->exit == true)
		return (1);
	res = replace_with_star(map, x - 1, y, data);
	if (res)
		return (res);
	res = replace_with_star(map, x + 1, y, data);
	if (res)
		return (res);
	res = replace_with_star(map, x, y - 1, data);
	if (res)
		return (res);
	res = replace_with_star(map, x, y + 1, data);
	return (res);
}

char	**map_duplicate(char **map)
{
	char	**map_cpy;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (map[x])
		x++;
	map_cpy = (char **)malloc(sizeof(char *) * (x + 1));
	if (!map_cpy)
	{
		free_split(map);
		exit(EXIT_FAILURE);
	}
	while (map[i])
	{
		map_cpy[i] = ft_strdup((const char *)map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}
