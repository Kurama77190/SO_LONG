/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:09:17 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/06 07:09:23 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_is_space(char c);

bool	ft_only_space(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_is_space(char c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t' \
	|| c == '\v' || c == 32);
}
