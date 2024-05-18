/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:44:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/17 23:05:35 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_malloc(t_garbage *memory, size_t size)
{
	void	*ptr;
	
	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc");
		ft_free_all(&memory);
		exit(1);
	}
	ft_lstadd_back_garbage(&memory, ft_lstnew_garbage(&memory, ptr, NULL, NULL));
	return (ptr);
}
