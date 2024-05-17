/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/17 18:16:25 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ft_init_animation(t_game *data);
void initialize_xpm_paths(t_game *data);

int	main(void)
{
	t_game	data;

	ft_init_animation(&data);
	return (0);
}

void	ft_init_animation(t_game *data)
{
	int	i;

	if (!data)
	{
		printf("Error init \n");
		exit(1);
	}
	initialize_xpm_paths(data);
	// data->animations[MOVE_UP]->frames = NULL;
	// data->animations[MOVE_DOWN]->frames = NULL;
	// data->animations[MOVE_LEFT]->frames = NULL;
	// data->animations[MOVE_RIGHT]->frames = NULL;
	i = 1;
	while (i++ <= 10)
		ft_lstadd_back(&data->animations[MOVE_UP]->frames, ft_lstnew(data->xpm[MOVE_DOWN][i], data));
	i = 0;
	while(i <= 10)
	{
		printf("%d xpm: %s", i, data->xpm[MOVE_DOWN][i]);
		i++;
	}	
}



void initialize_xpm_paths(t_game *data) {
    static const char *move_down[] = {
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_1.xpm",
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_2.xpm",
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_3.xpm",
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_4.xpm",
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_5.xpm",
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_6.xpm",
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_7.xpm",
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_8.xpm",
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_9.xpm",
        "src/Mandatory/img/sheetsprite/down/XPM/link_move_down_10.xpm"
    };
    data->xpm[MOVE_DOWN] = move_down;
}













// void testing(t_game *data);

// int main(void)
// {
// 	t_game data;

// 	data.memory_manager = NULL;
// 	char **test = ft_split("Salut je suis un roi\n", ' ', &data.memory_manager, "ROI");
// 	while (*test)
// 	{
// 		printf("%s ", *test);
// 		test++;
// 	}

// 	printf("\n");
// 	testing(&data);
// 	ft_free_all(&data.memory_manager);
// }

// void testing(t_game *data)
// {
// 	char *teste = ft_calloc(10, sizeof(char), data->memory_manager, "REINE");
// 	teste = "42_PARIS";

// 	printf("%s\n", teste);
// }
