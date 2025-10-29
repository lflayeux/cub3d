/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:50:45 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 12:16:41 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void rotate_player(t_player *player, float angle)
{
    float old_dir_x;
    float old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
    player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
    player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
    player->plane_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
    player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void	move_forward(t_game *game)
{
	t_player	*player;
	t_map		*map;
	float		new_x;
	float		new_y;

	player = &game->player;
	map = &game->map;

	new_x = player->pos_x + player->dir_x * MOVE_SPEED;
	new_y = player->pos_y + player->dir_y * MOVE_SPEED;

	if (map->map[(int)player->pos_y][(int)new_x] != '1' &&
		map->map[(int)(player->pos_y + COLLISION_MARGIN)][(int)new_x] != '1' &&
		map->map[(int)(player->pos_y - COLLISION_MARGIN)][(int)new_x] != '1')
		player->pos_x = new_x;

	if (map->map[(int)new_y][(int)player->pos_x] != '1' &&
		map->map[(int)new_y][(int)(player->pos_x + COLLISION_MARGIN)] != '1' &&
		map->map[(int)new_y][(int)(player->pos_x - COLLISION_MARGIN)] != '1')
		player->pos_y = new_y;
}

void	move_backward(t_game *game)
{
	t_player	*player;
	t_map		*map;
	float		new_x;
	float		new_y;

	player = &game->player;
	map = &game->map;

	new_x = player->pos_x - player->dir_x * MOVE_SPEED;
	new_y = player->pos_y - player->dir_y * MOVE_SPEED;

	if (map->map[(int)player->pos_y][(int)new_x] != '1' &&
		map->map[(int)(player->pos_y + COLLISION_MARGIN)][(int)new_x] != '1' &&
		map->map[(int)(player->pos_y - COLLISION_MARGIN)][(int)new_x] != '1')
		player->pos_x = new_x;

	if (map->map[(int)new_y][(int)player->pos_x] != '1' &&
		map->map[(int)new_y][(int)(player->pos_x + COLLISION_MARGIN)] != '1' &&
		map->map[(int)new_y][(int)(player->pos_x - COLLISION_MARGIN)] != '1')
		player->pos_y = new_y;
}

void	move_left(t_game *game)
{
	t_player	*player;
	t_map		*map;
	float		new_x;
	float		new_y;

	player = &game->player;
	map = &game->map;

	new_x = player->pos_x - player->plane_x * MOVE_SPEED;
	new_y = player->pos_y - player->plane_y * MOVE_SPEED;

	if (map->map[(int)player->pos_y][(int)new_x] != '1' &&
		map->map[(int)(player->pos_y + COLLISION_MARGIN)][(int)new_x] != '1' &&
		map->map[(int)(player->pos_y - COLLISION_MARGIN)][(int)new_x] != '1')
		player->pos_x = new_x;

	if (map->map[(int)new_y][(int)player->pos_x] != '1' &&
		map->map[(int)new_y][(int)(player->pos_x + COLLISION_MARGIN)] != '1' &&
		map->map[(int)new_y][(int)(player->pos_x - COLLISION_MARGIN)] != '1')
		player->pos_y = new_y;
}

void	move_right(t_game *game)
{
	t_player	*player;
	t_map		*map;
	float		new_x;
	float		new_y;

	player = &game->player;
	map = &game->map;

	new_x = player->pos_x + player->plane_x * MOVE_SPEED;
	new_y = player->pos_y + player->plane_y * MOVE_SPEED;

	if (map->map[(int)player->pos_y][(int)new_x] != '1' &&
		map->map[(int)(player->pos_y + COLLISION_MARGIN)][(int)new_x] != '1' &&
		map->map[(int)(player->pos_y - COLLISION_MARGIN)][(int)new_x] != '1')
		player->pos_x = new_x;

	if (map->map[(int)new_y][(int)player->pos_x] != '1' &&
		map->map[(int)new_y][(int)(player->pos_x + COLLISION_MARGIN)] != '1' &&
		map->map[(int)new_y][(int)(player->pos_x - COLLISION_MARGIN)] != '1')
		player->pos_y = new_y;
}