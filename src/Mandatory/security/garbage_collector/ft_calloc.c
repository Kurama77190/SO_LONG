/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 04:17:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/17 21:05:12 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		*ft_memset(void *b, int c, size_t len);
static size_t	ft_securite(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size, t_garbage **data, char *name)
{
	unsigned char	*tab;
	t_garbage		*new;
	t_garbage		*current;

	current = *data;
	tab = ft_malloc(ft_securite(count, size));
	if (!tab)
		return (NULL);
	new = ft_lstnew_garbage(data, tab, NULL, name);
	if (!new)
	{
		free(tab);
		return (NULL);
	}
	ft_lstadd_back_garbage(&current, new);
	if (!*data)
	{
		printf("initialize data : %p", current);
		*data = current;
	}
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
