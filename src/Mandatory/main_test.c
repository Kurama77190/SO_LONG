/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 01:37:51 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/17 15:37:40 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/08 01:36:38 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

typedef enum
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
} AnimationType;

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
	t_img						bg_img;   // Structure pour l'image de fond
	t_img						char_img; 
	t_img						heart_img; // Structure pour l'image du coeur
	t_img						enemy_img;
	t_animation					*animations[10]; //  // Structure pour l'animations du jeu
	int							direction;
	int							pos_char_x;
	int							pos_char_y;
	int							pos_enemy_x;
	int							pos_enemy_y;
	t_garbage					*memory_manager;
}								t_game;




void	load_image(t_img *img, void *mlx_ptr, const char *file)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, (char *)file, &img->width,
			&img->height);
	if (!img->img_ptr)
	{
		fprintf(stderr, "Failed to load image: %s\n", file);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length,
			&img->endian);
}

void	draw_image_with_transparency(t_game *data, t_img *img, int pos_x,
		int pos_y)
{
	int	y;
	int	x;
	int	pixel;
	int	trans_color;

	trans_color = 0x489848;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = *(int *)(img->addr + y * img->line_length + x * (img->bpp
						/ 8));
			if (pixel != trans_color)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos_x + x, pos_y
					+ y, pixel);
			x++;
		}
		y++;
	}
}

void draw_animation_frame(t_game *data, t_animation *anim, int x, int y)
{
    if (anim->current)
	{
        draw_image_with_transparency(data, anim->frames->img, x, y);
    }
}

void	advance_animation(t_animation *anim)
{
    if (anim->current && anim->current->next)
	{
        anim->current = anim->current->next;
    } else
	{
        anim->current = anim->frames; // Revenir à la première frame
    }
}


int	main(void)
{
	t_game data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = NULL;
	// Charger l'image de fond et celle du personnage
	load_image(&data.bg_img, data.mlx_ptr, "src/Mandatory/img/zelda.xpm");
	load_image(&data.char_img, data.mlx_ptr, "src/Mandatory/img/teste3.xpm");

	// Créer une nouvelle fenêtre adaptée à l'image de fond
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.bg_img.width,
			data.bg_img.height, "The Legend Of Zelda: A Link to MLX");

	// Afficher l'image de fond
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.bg_img.img_ptr, 0,
		0);

	// ft_init(&data);
	// Calculer la position centrale pour le personnage
	int char_x = (data.bg_img.width - data.char_img.width) / 2;
	int char_y = (data.bg_img.height - data.char_img.height) / 2;

	// Afficher l'image du personnage avec transparence
	draw_image_with_transparency(&data, &data.char_img, char_x, char_y);

	mlx_loop(data.mlx_ptr);
}