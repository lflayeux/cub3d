/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:29:10 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 15:29:43 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_ray_on_mini_map(t_game *game)
{
	t_map		*map;
	t_render_3d	render;
	float		ray_x;
	float		ray_y;
	int			x;

	map = &game->map;
	x = 0;
	while (x < WIDTH)
	{
		init_render(&render, &game->player, x);
		ray_x = game->player.pos_x;
		ray_y = game->player.pos_y;
		while ((int)ray_y >= 0 && (int)ray_x >= 0 && (int)ray_y < map->height
			&& (int)ray_x < map->width && map->map[(int)ray_y][(int)ray_x]
			!= '1')
		{
			my_mlx_pixel_put(game->mlx.img, ray_x * TILE_SIZE,
				ray_y * TILE_SIZE, 0xFFFF00);
			ray_x += render.ray_dir_x * 0.05;
			ray_y += render.ray_dir_y * 0.05;
		}
		x++;
	}
}
