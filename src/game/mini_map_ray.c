/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:29:10 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/22 17:10:01 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = dx - dy;

	while (true)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		int err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void draw_ray_on_mini_map(t_map *map, t_player *player, t_mlx *mlx)
{
    float camera_x;
    int i;
    double ray_dir_x, ray_dir_y;
    double ray_x, ray_y;

    i = 0;
    while (i < WIDTH)
    {
        camera_x = -1 + i * (2.0 / WIDTH);

        ray_dir_x = player->dir_x + player->plane_x * camera_x;
        ray_dir_y = player->dir_y + player->plane_y * camera_x;

        ray_x = player->pos_x;
        ray_y = player->pos_y;

        while ((int)ray_y < map->height && (int)ray_x < map->width
               && map->map[(int)ray_y][(int)ray_x] != '1')
        {
            ray_x += ray_dir_x * 0.0001;
            ray_y += ray_dir_y * 0.0001;
            my_mlx_pixel_put(mlx->img,ray_x * TILE_SIZE, ray_y * TILE_SIZE, 0xFFFF00);
        }
        i++;
    }
}