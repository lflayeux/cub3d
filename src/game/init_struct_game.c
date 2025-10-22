/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:46:00 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/22 15:52:37 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_mlx(t_params *param)
{
	param->mlx.mlx = mlx_init();
	if (!param->mlx.mlx)
		return (ERROR);
	param->mlx.win = mlx_new_window(param->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	if (!param->mlx.win)
		return (ERROR);
	param->mlx.img.img = mlx_new_image(param->mlx.mlx, WIDTH, HEIGHT);
	if (!param->mlx.img.img)
		return (ERROR);
	param->mlx.img.addr = mlx_get_data_addr(param->mlx.img.img,
		&param->mlx.img.bits_per_pixel, &param->mlx.img.line_length,&param->mlx.img.endian);
	if (!param->mlx.img.addr)
		return (ERROR);
	return (SUCCESS);
}

// tan((FOV/2.0) * (M_PI / 180.0)
// permet de convertir le radian en degre
// equivaut a tan(60/2)
void init_player_north_and_south(t_params *param, char dir)
{
	if (dir == 'n' || dir == 'N')
	{
		param->player.dir_x = 0.0;
		param->player.dir_y = -1.0;
		param->player.plane_x = tan((FOV/2.0) * (M_PI / 180.0));
		param->player.plane_y = 0.0;
	}
	else if (dir == 's' || dir == 'S')
	{
		param->player.dir_x = 0.0;
		param->player.dir_y = 1.0;
		param->player.plane_x = -tan((FOV/2.0) * (M_PI / 180.0));
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
		param->player.plane_y = -tan((FOV/2.0) * (M_PI / 180.0));
	}
	else if (dir == 'w' || dir == 'W')
	{
		param->player.dir_x = -1.0;
		param->player.dir_y = 0.0;
		param->player.plane_x = 0.0;
		param->player.plane_y = tan((FOV/2.0) * (M_PI / 180.0));
	}
}
void init_player(t_params *param)
{
	char dir;

	dir = param->map.map[param->map.player_y][param->map.player_x];
	param->player.pos_x = param->map.player_x + 0.5;
	param->player.pos_y = param->map.player_y + 0.5;
	init_player_north_and_south(param, dir);
	init_player_east_and_west(param, dir);
}