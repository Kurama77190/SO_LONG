/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:34:55 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/21 22:44:14 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*inventaire = NULL;
	char			*ligne;
	int				compteur;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &ligne, 0) < 0)
		return (NULL);
	compteur = 1;
	ligne = NULL;
	lire_et_addlist(fd, &inventaire, &compteur);
	if (inventaire == NULL)
		return (NULL);
	extraire_ligne(inventaire, &ligne);
	clean_inventaire(&inventaire);
	if (ligne[0] == '\0')
	{
		free_inventaire(inventaire);
		inventaire = NULL;
		free(ligne);
		return (NULL);
	}
	return (ligne);
}

/* Utilise read() pour acheter les caracteres dans t_list inventaire */

void	lire_et_addlist(int fd, t_list **inventaire, int *compteur)
{
	char	*buf;

	while (!found_newline(*inventaire) && *compteur != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		*compteur = (int)read(fd, buf, BUFFER_SIZE);
		if ((*inventaire == NULL && *compteur == 0) || *compteur == -1)
		{
			free(buf);
			return ;
		}
		buf[*compteur] = '\0';
		ajouter_a_inventaire(inventaire, buf, *compteur);
		free(buf);
	}
}

/* Ajout le contenue du buffer a la fin de ma t_list inventaire */

void	ajouter_a_inventaire(t_list **inventaire, char *buf, int compteur)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (compteur + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < compteur)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*inventaire == NULL)
	{
		*inventaire = new_node;
		return ;
	}
	last = ft_lst_get_last(*inventaire);
	last->next = new_node;
}

/* Extrait tous les caractères de l'inventaire et les stocke dans notre ligne.
 * s'arrêtant après le premier \n rencontré */

void	extraire_ligne(t_list *inventaire, char **ligne)
{
	int	i;
	int	j;

	if (inventaire == NULL)
		return ;
	malloc_ligne(ligne, inventaire);
	if (*ligne == NULL)
		return ;
	j = 0;
	while (inventaire)
	{
		i = 0;
		while (inventaire->content[i])
		{
			if (inventaire->content[i] == '\n')
			{
				(*ligne)[j++] = inventaire->content[i];
				break ;
			}
			(*ligne)[j++] = inventaire->content[i++];
		}
		inventaire = inventaire->next;
	}
	(*ligne)[j] = '\0';
}

/* Après l'extraction, on va liberer la memoire du noeud extrait. */

void	clean_inventaire(t_list	**inventaire)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*inventaire);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * \
	((ft_strlen(last->content) - i) + 1));
	if (clean_node == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_inventaire(*inventaire);
	*inventaire = clean_node;
}
