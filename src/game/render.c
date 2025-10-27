/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:50:21 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/27 11:56:23 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void draw_vertical_line(t_game *game, t_render_3d *render, int x)
{
	int y;
	
	y = 0;
    while (y < render->draw_start - 1)
	{
        my_mlx_pixel_put(game->mlx.img, x, y, 0x87CEFA);
		y++;
	}
	while (y < render->draw_end)
	{
        my_mlx_pixel_put(game->mlx.img, x, y, render->color);
		y++;	
	}
	while (y < HEIGHT)
	{
        my_mlx_pixel_put(game->mlx.img, x, y, game->col_text.Fcolor);
		y++;
	}
}
void draw_3d(t_game *game, t_render_3d *render, int x)
{
	if (render->side == 1)
		render->color = 0xAAAAAA;
	else
		render->color = 0xFFFFFF;
    draw_vertical_line(game, render, x);
}

void render_3d(t_game *game)
{
    t_player *player = &game->player;
    t_map *map = &game->map;
	t_render_3d	render;
	int x;

	x = 0;
    while (x < WIDTH)
    {
		init_render(&render, player, x);
		get_step_and_side_dist(&render, player);
		digital_differential_analysis(&render, map);
		get_wall_dist_and_height(&render, player);
		draw_3d(game, &render, x);
		x++;
    }
	
}