/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:35:11 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 17:44:18 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_direction(int keycode, t_game *game)
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

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		handle_exit(game);
	else
		handle_direction(keycode, game);
	return (SUCCESS);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx.win, 17, 0, handle_exit, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, handle_key_press, game);
}
