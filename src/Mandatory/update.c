/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:45:35 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/05 04:12:18 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     get_last_direction(t_player *player);
void    update_player(t_game *data);

int update_game(t_game *data)
{
    t_player *link;
    t_player *monster;

    link = data->player[LINK];
    monster = data->player[MONSTER];

    if (link->move_up)
        link->pos_y -= 5;
    if (link->move_down)
        link->pos_y += 5;
    if (link->move_left)
        link->pos_x -= 5;
    if (link->move_right)
        link->pos_x += 5;
    if (monster->move_up)
        monster->pos_y -= 3;
    if (monster->move_down)
        monster->pos_y += 3;
    if (monster->move_left)
        monster->pos_x -= 3;
    if (monster->move_right)
        monster->pos_x += 3;
    link->last_direction = get_last_direction(link);
    monster->last_direction = get_last_direction(monster);
    update_player(data);
    return (0);
}

int get_last_direction(t_player *player)
{
    if (player->move_up)
        return (MOVE_UP);
    if (player->move_down)
        return (MOVE_DOWN);
    if (player->move_left)
        return (MOVE_LEFT);
    if (player->move_right)
        return (MOVE_RIGHT);
    return (player->last_direction);
}

void    update_player(t_game *data)
{
    t_player *link;
    t_player *monster;

    link = data->player[LINK];
    monster = data->player[MONSTER];
    draw_image_to_image(data->buffer, data->bg_img, 0, 0);
    update_animation(data, link);
    update_animation(data, monster);
    // draw_image_with_transparency(data, data->pos_static[link->last_direction], link->pos_x, link->pos_y);
    // draw_image_with_transparency(data, data->pos_static[monster->last_direction], monster->pos_x, monster->pos_y);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buffer->img_ptr, 0, 0);
}




int update_animation(t_game *data, t_player *player)
{
    t_animation *animation = data->animations[player->last_direction];
    t_frame *current = animation->current;
    if (player->anime_actived == -1)
        return (0);
    if (current != NULL)
    {
        draw_animation_frame(data, animation, player->pos_x, player->pos_y);
        if (animation->frame_count % 3 == 0)
            animation->current = current->next;
        if (animation->current == NULL)
            animation->current = animation->frames;
        animation->frame_count++;
    }
    return (0);
}


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

