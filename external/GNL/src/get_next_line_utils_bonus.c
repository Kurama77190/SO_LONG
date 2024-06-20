/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.paris.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:41:38 by sben-tay          #+#    #+#             */
/*   Updated: 2023/12/22 02:50:15 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

int	found_newline(t_list *inventaire)
{
	int		i;
	t_list	*current;

	if (inventaire == NULL)
		return (0);
	i = 0;
	current = ft_lst_get_last(inventaire);
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list *inventaire)
{
	t_list	*current;

	current = inventaire;
	while (current && current->next)
	{
		current = current->next;
	}
	return (current);
}

void	malloc_ligne(char **ligne, t_list *inventaire)
{
	int	i;
	int	len;

	len = 0;
	while (inventaire)
	{
		i = 0;
		while (inventaire->content[i])
		{
			if (inventaire->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		inventaire = inventaire->next;
	}
	*ligne = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	free_inventaire(t_list *inventaire)
{
	t_list	*current;
	t_list	*next;

	current = inventaire;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
