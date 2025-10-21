/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:46:00 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/21 16:20:31 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_mlx(t_params *param)
{
	param->mlx.mlx = mlx_init();
	if (!param->mlx.mlx)
		return (ERROR);
	param->mlx.win = mlx_new_window(param->mlx.mlx, 1920,1080, "cub3d");
	if (!param->mlx.win)
		return (ERROR);
	param->mlx.img.img = mlx_new_image(param->mlx.mlx, 1920, 1080);
	if (!param->mlx.img.img)
		return (ERROR);
	param->mlx.img.addr = mlx_get_data_addr(param->mlx.img.img,
		&param->mlx.img.bits_per_pixel, &param->mlx.img.line_length,&param->mlx.img.endian);
	if (!param->mlx.img.addr)
		return (ERROR);
	return (SUCCESS);
}

void init_player_north_and_south(t_params *param, char dir)
{
	if (dir == 'n' || dir == 'N')
	{
		param->player.dir_x = 0.0;
		param->player.dir_y = -1.0;
		param->player.plane_x = 0.66;
		param->player.plane_y = 0.0;
	}
	else if (dir == 's' || dir == 'S')
	{
		param->player.dir_x = 0.0;
		param->player.dir_y = 1.0;
		param->player.plane_x = -0.66;
		param->player.plane_y = 0.0;
	}
}

void init_player_east_and_west(t_params *param, char dir)
{
	if (dir == 'e' || dir == 'E')
	{
		param->player.dir_x = 1.0;
		param->player.dir_y = 0.0;
		param->player.plane_x = 0.0;
		param->player.plane_y = -0.66;
	}
	else if (dir == 'w' || dir == 'W')
	{
		param->player.dir_x = -1.0;
		param->player.dir_y = 0.0;
		param->player.plane_x = 0.0;
		param->player.plane_y = 0.66;
	}
}
void init_player(t_params *param)
{
	char dir;

	dir = param->map.map[param->map.player_y][param->map.player_x];
	param->player.x = param->map.player_x + 0.5;
	param->player.y = param->map.player_y + 0.5;
	init_player_north_and_south(param, dir);
	init_player_east_and_west(param, dir);
}