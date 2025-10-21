/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:13:17 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/21 16:14:20 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_tile(t_mlx *mlx, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x * TILE_SIZE + i, y * TILE_SIZE + j, color);
			j++;
		}
		i++;
	}
}
void draw_map(t_mlx *mlx, t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				draw_tile(mlx, x, y, 0x3B2077);
			else if (map->map[y][x] == '0' || map->map[y][x] == 'N' ||
				map->map[y][x] == 'S' || map->map[y][x] == 'E' ||
				map->map[y][x] == 'W')
				draw_tile(mlx, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}


void draw_player(void *mlx, void *win, t_player *p)
{
	int player_screen_x;
	int player_screen_y;
	int i;
	int j;

	player_screen_x = (int)(p->x * TILE_SIZE);
	player_screen_y = (int)(p->y * TILE_SIZE);
	i = -5;
	while (i <=5)
	{
		j = -5;
		while (j <= 5)
		{
			mlx_pixel_put(mlx, win, player_screen_x + i, player_screen_y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}
void mini_map(t_params *param)
{
	draw_map(&param->mlx, &param->map);
	draw_player(param->mlx.mlx, param->mlx.win, &param->player);
}