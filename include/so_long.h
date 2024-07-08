/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:48:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/08 20:25:23 by sben-tay         ###   ########.fr       */
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
	RUBIS,
	EXIT,
	PLAYER,
	ENEMY
}	e_Assets;

typedef enum s_animation_type
{
	LINK,
	MONSTER,
	
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,

	MOVE_UP_M,
	MOVE_DOWN_M,
	MOVE_LEFT_M,
	MOVE_RIGHT_M,

	ATTACK_UP,
	ATTACK_DOWN,
	ATTACK_LEFT,
	ATTACK_RIGHT,

	ROLL_UP,
	ROLL_DOWN,
	ROLL_LEFT,
	ROLL_RIGHT
}	e_AnimationType;

typedef struct s_player
{
	int							last_direction;
	int							anime_actived;
	int							pos_x;
	int							pos_y;
	int							hitbox_up;
	int							hitbox_down;
	int							hitbox_left;
	int							hitbox_right;
	bool						move_up;
	bool						move_down;
	bool						move_left;
	bool						move_right;
}								t_player;

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
	t_img						*img;
	struct s_frame 				*next;
}								t_frame;

typedef struct s_animation
{
	t_frame						*frames;
	t_frame						*current;
	int							frame_count;
	int							current_index;
}								t_animation;

typedef struct s_garbage_collector
{
	char						*name;
	void						*alloc;
	void						**allocs;
	struct s_garbage_collector	*next;
}								t_garbage;

/*
	** Name for the garbage collector

	- LINK
	- MAP
	- ANIMATION
	- MONSTER
	
*/

typedef struct s_game
{
	t_img						*buffer;
	t_img						*bg_img;
	t_img						*assets[10];
	t_img						*pos_static[10];
	t_player					*player[2];
	t_animation					*animations[10];
	t_garbage					*memory_manager;
	void						*mlx_ptr;
	void						*win_ptr;
	char						**map;
	char						*n_map;
	bool						a_life;
	int							hitbox_size;
	int							all_ruby;
	int							ruby_counter;
	int							step_counter;
	int							exit_x;
	int							exit_y;
	int							map_width;
	int							map_height;
}								t_game;

//	UTILS AND FUNCTIONS GARBAGE
void							ft_lstadd_back_garbage(t_garbage **alst, t_garbage *new);
t_garbage						*ft_lstnew_garbage(t_garbage **aslt, void *content, void **split, char *name);
void							ft_free_all(t_garbage **lst, t_game *data);
void							secure_exit(t_game *data);
void							ft_free_img(t_img *img, void *mlx_ptr);


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
int								update_game(t_game *data);
void							load_image(t_game *data, t_img *img, const char *file);
void							load_animation(t_game *data, e_AnimationType action, const char *paths[]);
void							init_img(t_game *data);
void							init_start_over(t_game *data);




// FUNCTIONS DRAW
void							put_pixel_to_image(t_img *img, int x, int y, int color);
void							init_map(t_game *data);
void							draw_background_region(t_game *data, int x, int y);
void							draw_animation_frame(t_game *data, t_animation *anim, int x, int y);

// FUNCTIONS MAPS

char							**read_map(t_game *data, const char *filename, int *width, int *height);
int								get_map_width(const char *filename);
int								count_lines(const char *filename);
void							draw_image_to_image(t_img *dest_img, t_img *src_img, int x, int y);
void							put_pixel_to_image(t_img *img, int x, int y, int color);
void							draw_image_to_image(t_img *dest_img, t_img *src_img, int x, int y);

// FUNCTIONS KEYS_EVENEMENT

bool							is_walkable(t_game *data, int x, int y);
bool							is_walkable_m(t_game *data, int x, int y);
void							open_exit(t_game *data);	

#endif