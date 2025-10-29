/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:35:11 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 19:29:09 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_direction(t_game *game)
{
	if (game->player.w_press == true)
		move_forward(game);
	if (game->player.a_press == true)
		move_left(game);
	if (game->player.s_press == true)
		move_backward(game);
	if (game->player.d_press == true)
		move_right(game);
	if (game->player.left_arrow_press == true)
		rotate_player(&game->player, -0.05);
	if (game->player.right_arrow_press == true)
		rotate_player(&game->player, 0.05);
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

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.w_press = false;
	if (keycode == A)
		game->player.a_press = false;
	if (keycode == S)
		game->player.s_press = false;
	if (keycode == D)
		game->player.d_press = false;
	if (keycode == LEFT_ARROW)
		game->player.left_arrow_press = false;
	if (keycode == RIGHT_ARROW)
		game->player.right_arrow_press = false;
	return (SUCCESS);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		handle_exit(game);
	if (keycode == W)
		game->player.w_press = true;
	if (keycode == A)
		game->player.a_press = true;
	if (keycode == S)
		game->player.s_press = true;
	if (keycode == D)
		game->player.d_press = true;
	if (keycode == LEFT_ARROW)
		game->player.left_arrow_press = true;
	if (keycode == RIGHT_ARROW)
		game->player.right_arrow_press = true;
	return (SUCCESS);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx.win, 17, 0, handle_exit, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->mlx.win, 3, 1L << 1, handle_key_release, game);
	mlx_loop_hook(game->mlx.mlx, handle_direction, game);
}
