/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:01:56 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 16:32:56 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "struct.h"

// =============================
// ========= MAIN PART =========
// =============================
void	cub3d_game(t_game *game);
int		game_loop(t_game *game);

// =============================
// ==========  MINIMAP =========
// =============================
void	mini_map(t_game *game);
void	draw_ray_on_mini_map(t_game *game);

// =============================
// ========= RENDERING =========
// =============================

void	my_mlx_pixel_put(t_data img, int x, int y, int color);
void	render_3d(t_game *game);
void	draw_3d(t_game *game, t_render_3d *render, int x);
void	draw_vertical_line(t_game *game, t_render_3d *render, int x);
void	get_wall_dist_and_height(t_render_3d *render, t_player *player);
void	init_render(t_render_3d *render, t_player *player, int x);
void	get_step_and_side_dist(t_render_3d *render, t_player *player);
void	digital_differential_analysis(t_render_3d *render, t_map *map);

// =============================
// ============ UTILS ==========
// =============================

void	init_player(t_game *game);
void	boundaries(t_texture *texture, int *x, int *y);

#endif