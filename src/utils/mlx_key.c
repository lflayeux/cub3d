/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle_direction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:35:11 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/23 17:46:05 by pandemonium      ###   ########.fr       */
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

int handle_direction(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.pos_y -= 0.5;
	if (keycode == A)
		game->player.pos_x -= 0.5;
	if (keycode == S)
		game->player.pos_y += 0.5;
	if (keycode == D)
		game->player.pos_x += 0.5;
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