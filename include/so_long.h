/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:48:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/06 20:25:56 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>

typedef struct s_game
{
	void					*mlx;
	void					*win;
}							t_game;

typedef struct s_img
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
}							t_img;

typedef struct s_map
{
	char					**map;
	int						width;
	int						height;
}							t_map;

typedef struct s_player
{
	int						x;
	int						y;
}							t_player;

typedef struct s_collectible
{
	int						x;
	int						y;
}							t_collectible;

typedef struct s_exit
{
	int						x;
	int						y;
}							t_exit;

typedef struct s_game_object
{
	t_player				player;
	t_collectible			*collectibles;
	t_exit					exit;
}							t_game_object;

typedef struct s_garbage_collector
{
	void						*alloc;
	void						**allocs;
	struct s_garbage_collector	*next;
}							t_garbage;

typedef struct s_game_data
{
	int						return_value;
	t_game					game;
	t_img					img;
	t_map					map;
	t_game_object			game_object;
	t_garbage				*memory_data;
}							t_game_data;


void		ft_free(void *ptr);
void		free_split(char **strs);
void		ft_free_all(t_garbage **lst);
void		*ft_calloc(size_t count, size_t size, t_garbage *data);
void		ft_lstadd_back_garbage(t_garbage **alst, t_garbage *new);
char		**ft_split(char const *s, char c, t_garbage **data);
t_garbage	*ft_lstnew_garbage(t_garbage **aslt, void *content, void **split);
bool		ft_only_space(char *str);



#endif