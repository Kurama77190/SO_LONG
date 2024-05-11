/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:48:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/11 10:42:58 by sben-tay         ###   ########.fr       */
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

#define DIRECTION_UP 99
#define DIRECTION_DOWN 98
#define DIRECTION_LEFT 97
#define DIRECTION_RIGHT 96
#define DIRECTION_UP_LEFT 95
#define DIRECTION_UP_RIGHT 94
#define DIRECTION_DOWN_LEFT 93
#define DIRECTION_DOWN_RIGHT 92


#define KEY_ESC 91
#define KEY_W 90
#define KEY_A 89
#define KEY_S 88
#define KEY_D 87
#define KEY_SPACE 86
#define KEY_LEFT 85
#define KEY_RIGHT 84
#define KEY_DOWN 83
#define KEY_UP 82
#define KEY_Q 81
#define KEY_E 80

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_frame
{
	t_img			img;            // Structure pour stocker l'image de la frame
	struct s_frame *next; 			// Pointeur vers la prochaine frame
}					t_frame;

typedef struct s_animation
{
	t_frame	*frames;   // Pointeur vers la première frame
	t_frame	*current;  // Frame actuellement affichée
	int		frame_count;   // Nombre total de frames
	int		current_index; // Index de la frame actuelle
}			t_animation;

typedef struct s_garbage_collector
{
	char						*name;
	void						*alloc;
	void						**allocs;
	t_frame						**animations;
	struct s_garbage_collector	*next;
}							t_garbage;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		bg_img;   // Structure pour l'image de fond
	t_img		char_img; // Structure pour l'image du personnage
	t_animation char_anim[10]; // Structure pour l'animation du personnage
	t_animation char_attack[5]; // Structure pour l'animation de l'attaque du personnage
	t_img		heart_img; // Structure pour l'image du coeur
	t_img		enemy_img; // Structure pour l'image de l'ennemi
	t_animation enemy_anim; // Structure pour l'animation de l'ennemi
	t_img		sword_img; // Structure pour l'image de l'épée
	t_animation sword_anim; // Structure pour l'animation de l'épée
	int			direction;
	int			pos_char_x;
	int			pos_char_y;
	int			pos_enemy_x;
	int			pos_enemy_y;
	t_garbage	*memory_manager;
}				t_data;



void		ft_free(void *ptr);
void		free_split(char **strs);
void		ft_free_all(t_garbage **lst);
void		*ft_calloc(size_t count, size_t size, t_garbage *data, char *name);
void		ft_lstadd_back_garbage(t_garbage **alst, t_garbage *new);
char		**ft_split(char const *s, char c, t_garbage **data, char *name);
t_garbage	*ft_lstnew_garbage(t_garbage **aslt, void *content, void **split, char *name);
bool		ft_only_space(char *str);



#endif