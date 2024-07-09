/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 04:17:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/09 16:24:25 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void			*ft_memset(void *b, int c, size_t len);
static size_t		ft_securite(size_t count, size_t size);



void	*ft_calloc(size_t count, size_t size, t_garbage *data, char *name)
{
	unsigned char	*tab;
	t_garbage		*current;
	t_garbage		*new;

	new = ft_lstnew_garbage(&data, NULL, NULL, name);
	if (!new)
		return (NULL);
	current = data;
	tab = malloc(ft_securite(count, size));
	if (!tab)
		return (NULL);
	else
		ft_lstadd_back_garbage(&current, new);
	ft_memset(tab, 0, ft_securite(count, size));
	return (tab);
}

static size_t	ft_securite(size_t count, size_t size)
{
	size_t	size_max;

	size_max = LONG_MAX;
	if (count == 0 || size == 0)
		return (0);
	if (count > size_max / size || size > size_max / count)
		return (LONG_MAX);
	return (count * size);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
