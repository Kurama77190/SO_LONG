/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:48:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/06/29 23:55:08 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
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
# include "../external/GNL/include/get_next_line.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SPACE 32
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_Q 113
# define KEY_E 101

# define S_UP 1
# define S_LEFT 2
# define S_RIGHT 3
# define S_DOWN 4

typedef enum s_assets
{
	WALL,
	FLOOR,
	COLLECTIBLE,
	EXIT,
	PLAYER,
	ENEMY
}	e_Assets;

typedef enum s_animation_type
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,

	ATTACK_UP,
	ATTACK_DOWN,
	ATTACK_LEFT,
	ATTACK_RIGHT,

	ROLL_UP,
	ROLL_DOWN,
	ROLL_LEFT,
	ROLL_RIGHT
}	e_AnimationType;

typedef struct s_img
{
	void						*img_ptr;
	char						*addr;
	int							bpp;
	int							line_length;
	int							endian;
	int							width;
	int							height;
}								t_img;

typedef struct s_frame
{
	t_img						*img;            // Structure pour stocker l'image de la frame
	struct s_frame 				*next; 			// Pointeur vers la prochaine frame
}								t_frame;

typedef struct s_animation
{
	t_frame						*frames;   // Pointeur vers la première frame
	t_frame						*current;  // Frame actuellement affichée
	int							frame_count;   // Nombre total de frames
	int							current_index; // Index de la frame actuelle
}								t_animation;

typedef struct s_garbage_collector
{
	char						*name;
	void						*alloc;
	void						**allocs;
	t_frame						**animations;
	struct s_garbage_collector	*next;
}								t_garbage;

typedef struct s_game
{
	void						*mlx_ptr;
	void						*win_ptr;
	t_img						*bg_img;   // Structure pour l'image de fond
	char						**map;
	t_img						*assets[10];
	char						*n_map;
	int							map_width;
	int							map_height;
	t_img						heart_img; // Structure pour l'image du coeur
	t_img						enemy_img;
	t_img						*pos_static[4];
	t_animation					*animations[10]; // Structure pour l'animations du jeu
	int							anim_actived;
	int							last_direction;
	int							pos_char_x;
	int							pos_char_y;
	int							pos_enemy_x;
	int							pos_enemy_y;
	t_garbage					*memory_manager;
	//				TEST		//
	t_img						*wall_img;
}								t_game;

//	UTILS AND FUNCTIONS GARBAGE
void							ft_lstadd_back_garbage(t_garbage **alst, t_garbage *new);
t_garbage						*ft_lstnew_garbage(t_garbage **aslt, void *content, void **split, char *name);
void							ft_free_all(t_garbage **lst);
void							*ft_calloc(size_t count, size_t size, t_garbage *data, char *name);

// LIB
int								ft_tab_len(const char **strs);
void							ft_free(void *ptr);
void							free_split(char **strs);
char							**ft_split(char const *s, char c, t_garbage **data, char *name);
bool							ft_only_space(char *str);
void							ft_lstclear(t_frame **lst, t_game *data);
t_frame							*ft_lstnew(const char *content, t_game *data);
void							ft_lstadd_back(t_frame **alst, t_frame *new);
void							*ft_malloc(t_garbage *memory, size_t size);

// MLX ANIMATIONS AND INITIALIZING
void							ft_init_game(t_game *data);
void							init_animations(t_game *data);
char							**read_map(t_game *data, const char *filename, int *width, int *height);
int								keyrelease_hook(int keycode, t_game *data);
int								keypress_hook(int keycode, t_game *data);
int								update_animation(t_game *data);
void							load_image(t_game *data, t_img *img, const char *file);
void							load_animation(t_game *data, e_AnimationType action, const char *paths[]);


// FUNCTIONS DRAW
void							init_map(t_game *data);
void							draw_background_region(t_game *data, int x, int y, int width, int height);
void							draw_background(t_game *data);
void							draw_animation_frame(t_game *data, t_animation *anim, int x, int y);
void							draw_static_frame(t_game *data, t_img *static_img);
void							draw_image_with_transparency(t_game *data, t_img *img, int pos_x, \
								int pos_y);

// FUNCTIONS MAPS

char	**read_map(t_game *data, const char *filename, int *width, int *height);
int		get_map_width(const char *filename);
int		count_lines(const char *filename);
void	draw_image_to_image(t_img *dest_img, t_img *src_img, int x, int y);
void	put_pixel_to_image(t_img *img, int x, int y, int color);
void	draw_image_to_image(t_img *dest_img, t_img *src_img, int x, int y);
void	draw_element(t_game *data, t_img *element_img, int x, int y);




#endif