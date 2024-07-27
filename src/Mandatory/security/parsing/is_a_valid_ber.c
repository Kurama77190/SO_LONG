/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_valid_ber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:37:05 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/27 09:38:40 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_is_ber(char *str);

int	is_a_valid_ber(char *n_map)
{
	if (!check_is_ber(n_map))
	{
		ft_putstr_fd("Error.\nYour file doesn't have the good \
		extension(.ber)\n", 2);
		exit(EXIT_FAILURE);
	}
	return (SUCCESS);
}

bool	check_is_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] != 'r')
		return (false);
	i--;
	if (str[i] != 'e')
		return (false);
	i--;
	if (str[i] != 'b')
		return (false);
	i--;
	if (str[i] != '.')
		return (false);
	return (true);
}
