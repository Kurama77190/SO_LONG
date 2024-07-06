/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:45:35 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/06 02:25:26 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     get_last_direction(t_player *player1, t_player *player2);
void    update_player(t_game *data);

int update_game(t_game *data)
{
    t_player *link;
    t_player *monster;

    link = data->player[LINK];
    monster = data->player[MONSTER];
    if (link->move_up)
        link->pos_y -= 5;
    else if (link->move_down)
        link->pos_y += 5;
    else if (link->move_left)
        link->pos_x -= 5;
    else if (link->move_right)
        link->pos_x += 5;
    if (monster->move_up)
        monster->pos_y -= 3;
    else if (monster->move_down)
        monster->pos_y += 3;
    else if (monster->move_left)
        monster->pos_x -= 3;
    else if (monster->move_right)
        monster->pos_x += 3;
    link->last_direction = get_last_direction(link, NULL);
    monster->last_direction = get_last_direction(NULL, monster);
    update_player(data);
    return (0);
}

int get_last_direction(t_player *player1, t_player *player2)
{
    if (player1)
    {
    if (player1->move_up)
        return (MOVE_UP);
    else if (player1->move_down)
        return (MOVE_DOWN);
    else if (player1->move_left)
        return (MOVE_LEFT);
    else if (player1->move_right)
        return (MOVE_RIGHT);
    return (player1->last_direction);    
    }
    if (player2)
    {
    if (player2->move_up)
        return (MOVE_UP_M);
    else if (player2->move_down)
        return (MOVE_DOWN_M);
    else if (player2->move_left)
        return (MOVE_LEFT_M);
    else if (player2->move_right)
        return (MOVE_RIGHT_M);
    return (player2->last_direction);    
    }
    return (MOVE_DOWN);
}

void    update_player(t_game *data)
{
    t_player *link;
    t_player *monster;
    // t_img    *link_pos;
    // t_img    *monster_pos;

    link = data->player[LINK];
    monster = data->player[MONSTER];
    // link_pos = data->pos_static[link->last_direction];
    // monster_pos = data->pos_static[monster->last_direction];
    draw_image_to_image(data->buffer, data->bg_img, 0, 0);
    if (link->anime_actived != -1)
        update_animation(data, link);
    else
        draw_image_with_transparency(data, data->pos_static[link->last_direction], link->pos_x, link->pos_y);

    // Mettre à jour l'animation du monstre
    if (monster->anime_actived != -1)
        update_animation(data, monster);
    else
        draw_image_with_transparency(data, data->pos_static[monster->last_direction], monster->pos_x, monster->pos_y);

    // Afficher le buffer
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buffer->img_ptr, 0, 0);
}
//     if (link->anime_actived == 1 || monster->anime_actived == 1)
//     {
//     update_animation(data, link);
//     update_animation(data, monster);
//     }
//     else
//     {
//         draw_image_to_image(data->buffer, data->bg_img, 0, 0);
//         draw_image_with_transparency(data, link_pos, link->pos_x, link->pos_y);
//         draw_image_with_transparency(data, monster_pos, monster->pos_x, monster->pos_y);
//     }
//     mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buffer->img_ptr, 0, 0);
// }

int update_animation(t_game *data, t_player *player)
{
    if (player->anime_actived == -1)
        return 0;

    t_animation *animation = data->animations[player->last_direction];
    t_frame *current = animation->current;

    if (current != NULL)
    {
        draw_animation_frame(data, animation, player->pos_x, player->pos_y);
        if (animation->frame_count % 5 == 0)
            animation->current = current->next;

        if (animation->current == NULL)
            animation->current = animation->frames;
        animation->frame_count++;
    }

    return 0;
}


// int update_animation(t_game *data, t_player *player)
// {
//     t_animation *animation = data->animations[player->last_direction];
//     t_frame *current = animation->current;
//     if (player->anime_actived == -1)
//         return (0);
//     if (current != NULL)
//     {
//         draw_animation_frame(data, animation, player->pos_x, player->pos_y);
//         if (animation->frame_count % 3 == 0)
//             animation->current = current->next;
//         if (animation->current == NULL)
//             animation->current = animation->frames;
//         animation->frame_count++;
//     }
//     return (0);
// }


// int update_animation_m(t_game *data)
// {
//     t_animation *animation;
//     t_frame *current;
//     if (data->anim_actived_m == -1)
//         return (0);
//     animation = data->animations[data->anim_actived_m];
//     current = animation->current;
//     if (current != NULL)
//     {
//         draw_animation_frame(data, animation, data->pos_enemy_x, data->pos_enemy_y);
//         if (animation->frame_count % 110 == 0)
//             animation->current = current->next;
        
//         if (animation->current == NULL)
//             animation->current = animation->frames;
//         animation->frame_count++;
//     }
//     return (0);
// }

// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠈⢆⠀⠀⠀⠈⣹⣷⣀⣴⠀⢠⣤⣶⡦⠀⠀⠀⠀⠀⠀
// ⠢⣀⠀⠀⠀⠀⠀⢄⠀⠈⣆⣠⣼⣿⣿⣿⣿⣿⣦⣼⣏⡀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠈⠻⣶⣄⡀⠀⣨⣷⡿⠟⠋⠉⠉⠉⠉⠛⠿⣿⣿⣿⣧⣀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠙⢿⣿⡿⠋⠀⠀⠀⠀⢠⡄⠀⠀⠀⠈⠙⣿⣿⣏⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⣠⣿⣿⣆⠀⠀⠀⠀⠈⣿⣿⡁⠀⠀⠀⠀⠀
// ⠀⠀⠀⠒⢺⣿⠁⠀⠀⠀⠀⡰⠿⠿⠿⠿⢆⠀⠀⠀⠀⠸⣿⡿⠃⠀⠀⠀⠀
// ⠀⠀⠀⢠⣾⣿⠀⠀⠀⠀⣴⣷⡀⠀⠀⢀⣼⣦⠀⠀⠀⠀⣿⣿⠆⠀⠀⠀⠀
// ⠀⠀⠀⠀⣹⣿⠀⠀⠀⣼⣿⣿⣷⡀⢀⣾⣿⣿⣧⡀⠀⢠⣿⡧⠤⠀⠀⠀⠀
// ⠀⠀⠀⠈⠛⢿⣆⠀⠈⠉⠉⠉⠉⠉⠈⠉⠉⠉⠉⠁⠀⣼⡿⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠻⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣷⣄⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠚⢻⣿⣿⣦⣄⡀⠀⠀⠀⠀⢀⣠⣶⣿⡋⠀⠈⠙⠻⣦⡀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⢙⣿⠿⢿⣿⣿⣿⣿⣿⠛⠙⡁⠀⠁⠀⠀⠀⠀⠀⠉⠂⠄
// ⠀⠀⠀⠀⠀⠰⣶⡾⠿⠀⠸⠋⠻⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//		© 2024 - sben-tay - 42 PARIS

