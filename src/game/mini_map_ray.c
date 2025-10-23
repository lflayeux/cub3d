/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:29:10 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/23 15:04:36 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void digital_differential_analyzer(t_game *game, float x1, float y1, int color)
{
	float dx;
	float dy;
	int steps;
	float x;
	float y;
	float inc_x;
	float inc_y;
	int i;

	x = game->player.pos_x * TILE_SIZE;
	y = game->player.pos_y * TILE_SIZE;
	dx = x1 - x;
	dy = y1 - y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	inc_x = dx / (float)steps;
	inc_y = dy / (float)steps;
	i = 0;
	while (i < steps)
	{
		my_mlx_pixel_put(game->mlx.img, (int)x, (int)y, color);
		x += inc_x;
		y += inc_y;
		i++;
	}
}

void draw_ray_on_mini_map(t_game *game, t_map *map, t_player *player)
{
    float camera;
    int i;
    float	ray_dir_x;
	float	ray_dir_y;
    float	dest_x;
	float	dest_y;

    i = 0;
    while (i < WIDTH)
    {
        camera = -1 + i * (2.0 / WIDTH);
        ray_dir_x = player->dir_x + player->plane_x * camera;
        ray_dir_y = player->dir_y + player->plane_y * camera;
        dest_x = player->pos_x;
        dest_y = player->pos_y;
		while (dest_x >= 0 && dest_y >= 0
		       && (int)dest_y < map->height && (int)dest_x < map->width)
        {
            dest_x += ray_dir_x * 0.05;
            dest_y += ray_dir_y * 0.05;
			my_mlx_pixel_put();
        }
		// digital_differential_analyzer(game, dest_x * TILE_SIZE, dest_y * TILE_SIZE, 0xFFFF00);
        i++;
    }
}