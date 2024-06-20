/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.paris.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:05:42 by sben-tay          #+#    #+#             */
/*   Updated: 2023/12/19 02:33:03 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

int		found_newline(t_list *inventaire);

t_list	*ft_lst_get_last(t_list *inventaire);

void	lire_et_addlist(int fd, t_list **inventaire, int *compteur);

void	ajouter_a_inventaire(t_list **inventaire, char *buf, int compteur);

void	extraire_ligne(t_list *inventaire, char **ligne);

void	malloc_ligne(char **ligne, t_list *inventaire);

void	clean_inventaire(t_list	**inventaire);

int		ft_strlen(char *str);

void	free_inventaire(t_list *inventaire);

#endif