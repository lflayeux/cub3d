/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:56:11 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 15:43:21 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	digital_differential_analysis(t_render_3d *render, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (render->side_dist_x < render->side_dist_y)
		{
			render->side_dist_x += render->delta_dist_x;
			render->map_x += render->step_x;
			render->side = 0;
		}
		else
		{
			render->side_dist_y += render->delta_dist_y;
			render->map_y += render->step_y;
			render->side = 1;
		}
		if (map->map[render->map_y][render->map_x] == '1')
			hit = 1;
	}
}

void	get_step_and_side_dist(t_render_3d *render, t_player *player)
{
	if (render->ray_dir_x < 0)
	{
		render->step_x = -1;
		render->side_dist_x = (player->pos_x - render->map_x)
			* render->delta_dist_x;
	}
	else
	{
		render->step_x = 1;
		render->side_dist_x = (render->map_x + 1.0 - player->pos_x)
			* render->delta_dist_x;
	}
	if (render->ray_dir_y < 0)
	{
		render->step_y = -1;
		render->side_dist_y = (player->pos_y - render->map_y)
			* render->delta_dist_y;
	}
	else
	{
		render->step_y = 1;
		render->side_dist_y = (render->map_y + 1.0 - player->pos_y)
			* render->delta_dist_y;
	}
}

void	get_wall_dist_and_height(t_render_3d *render, t_player *player)
{
	if (render->side == 0)
		render->perp_wall_dist = (render->map_x - player->pos_x
				+ (1 - render->step_x) / 2) / render->ray_dir_x;
	else
		render->perp_wall_dist = (render->map_y - player->pos_y
				+ (1 - render->step_y) / 2) / render->ray_dir_y;
	render->line_height = (int)(HEIGHT / render->perp_wall_dist);
	render->draw_start = -render->line_height / 2 + HEIGHT / 2;
	if (render->draw_start < 0)
		render->draw_start = 0;
	render->draw_end = render->line_height / 2 + HEIGHT / 2;
	if (render->draw_end >= HEIGHT)
		render->draw_end = HEIGHT - 1;
}

void	init_render(t_render_3d *render, t_player *player, int x)
{
	render->camera = 2 * x / (float)WIDTH - 1;
	render->map_x = (int)player->pos_x;
	render->map_y = (int)player->pos_y;
	render->ray_dir_x = player->dir_x + player->plane_x * render->camera;
	render->ray_dir_y = player->dir_y + player->plane_y * render->camera;
	render->delta_dist_x = fabs(1 / render->ray_dir_x);
	render->delta_dist_y = fabs(1 / render->ray_dir_y);
}
