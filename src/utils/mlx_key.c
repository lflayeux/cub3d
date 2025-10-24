/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:35:11 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/24 14:58:46 by pandemonium      ###   ########.fr       */
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
	float new_x;
	float new_y;
	
	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
    if (game->map.map[(int)new_y][(int)new_x] != '1')
    {
        game->player.pos_x = new_x;
        game->player.pos_y = new_y;
    }
}

void	move_backward(t_game *game)
{
	float new_x;
	float new_y;
	
	new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
    if (game->map.map[(int)new_y][(int)new_x] != '1')
    {
        game->player.pos_x = new_x;
        game->player.pos_y = new_y;
    }
}

void	move_left(t_game *game)
{
	float new_x;
	float new_y;
	
	new_x = game->player.pos_x - game->player.plane_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.plane_y * MOVE_SPEED;
    if (game->map.map[(int)new_y][(int)new_x] != '1')
    {
        game->player.pos_x = new_x;
        game->player.pos_y = new_y;
    }
}

void	move_right(t_game *game)
{
	float new_x;
	float new_y;
	
	new_x = game->player.pos_x + game->player.plane_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.plane_y * MOVE_SPEED;
    if (game->map.map[(int)new_y][(int)new_x] != '1')
    {
        game->player.pos_x = new_x;
        game->player.pos_y = new_y;
    }
}

int handle_direction(int keycode, t_game *game)
{
	if (keycode == W)
		move_forward(game);
	if (keycode == A)
		move_left(game);
	if (keycode == S)
		move_backward(game);
	if (keycode == D)
		move_right(game);
	if (keycode == LEFT_ARROW)
		rotate_player(&game->player, -0.1);	
	if (keycode == RIGHT_ARROW)
		rotate_player(&game->player, 0.1);
	game_loop(game);
	return (SUCCESS);
}

int	handle_exit(t_game *game)
{
	destroy_mlx(game);
	free_game(game);
	exit(SUCCESS);
	return (SUCCESS);
}
void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx.win, 17, 0, handle_exit, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, handle_direction, game);	
}