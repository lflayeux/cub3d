/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:46:00 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 19:07:14 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (ERROR);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	if (!game->mlx.win)
		return (ERROR);
	return (SUCCESS);
}

void	init_player_north_and_south(t_game *game, char dir)
{
	if (dir == 'n' || dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
		game->player.plane_x = tan((FOV / 2.0) * (M_PI / 180.0));
		game->player.plane_y = 0.0;
	}
	else if (dir == 's' || dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.plane_x = -tan((FOV / 2.0) * (M_PI / 180.0));
		game->player.plane_y = 0.0;
	}
}

void	init_player_east_and_west(t_game *game, char dir)
{
	if (dir == 'e' || dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = -tan((FOV / 2.0) * (M_PI / 180.0));
	}
	else if (dir == 'w' || dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = tan((FOV / 2.0) * (M_PI / 180.0));
	}
}

void	init_player(t_game *game)
{
	char	dir;

	dir = game->map.map[game->map.player_y][game->map.player_x];
	game->player.pos_x = game->map.player_x + 0.5;
	game->player.pos_y = game->map.player_y + 0.5;
	init_player_north_and_south(game, dir);
	init_player_east_and_west(game, dir);
	game->player.w_press = false;
	game->player.a_press = false;
	game->player.s_press = false;
	game->player.d_press = false;
	game->player.left_arrow_press = false;
	game->player.right_arrow_press = false;
}
