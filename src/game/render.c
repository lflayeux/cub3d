/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:50:21 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 16:45:54 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_print_wall_line(t_game *game, t_render_3d *_3d, t_wall_line *wall)
{
	if (_3d->side == 0)
		wall->wall_x = game->player.pos_y + _3d->perp_wall_dist
			* _3d->ray_dir_y;
	else
		wall->wall_x = game->player.pos_x + _3d->perp_wall_dist
			* _3d->ray_dir_x;
	wall->wall_x -= floor(wall->wall_x);
	wall->tex_x = (int)(wall->wall_x * (float)_3d->texture->width);
	wall->step = (float)_3d->texture->height / (float)_3d->line_height;
	wall->tex_pos = 0;
	wall->y = _3d->draw_start;
	if (_3d->line_height > HEIGHT)
		wall->tex_pos = ((_3d->line_height - HEIGHT) / 2.0) * wall->step;
}

void	print_wall_line(t_game *game, t_render_3d *_3d, int x)
{
	t_texture	*texture;
	t_wall_line	wall;

	texture = _3d->texture;
	ft_memset(&wall, 0, sizeof(t_wall_line));
	init_print_wall_line(game, _3d, &wall);
	while (wall.y < _3d->draw_end)
	{
		wall.tex_y = (int)wall.tex_pos;
		boundaries(texture, &wall.tex_x, &wall.tex_y);
		wall.color = *(unsigned int *)(texture->addr
				+ (wall.tex_y * texture->line_length + wall.tex_x
					* (texture->bits_per_pixel / 8)));
		my_mlx_pixel_put(game->mlx.img, x, wall.y, wall.color);
		wall.tex_pos += wall.step;
		wall.y++;
	}
}

void	draw_vertical_line(t_game *game, t_render_3d *render, int x)
{
	int	y;

	y = 0;
	while (y < render->draw_start - 1)
	{
		my_mlx_pixel_put(game->mlx.img, x, y, game->textures.ceiling_color);
		y++;
	}
	print_wall_line(game, render, x);
	y = render->draw_end;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(game->mlx.img, x, y, game->textures.floor_color);
		y++;
	}
}

void	draw_3d(t_game *game, t_render_3d *render, int x)
{
	if (render->side == 0)
	{
		if (render->step_x < 0)
			render->texture = &game->textures.west;
		else
			render->texture = &game->textures.east;
	}
	else
	{
		if (render->step_y < 0)
			render->texture = &game->textures.north;
		else
			render->texture = &game->textures.south;
	}
	draw_vertical_line(game, render, x);
}

void	render_3d(t_game *game)
{
	t_player	*player;
	t_map		*map;
	t_render_3d	render;
	int			x;

	player = &game->player;
	map = &game->map;
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
