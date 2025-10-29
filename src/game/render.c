/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:50:21 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/28 18:45:53 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

// static void draw_wall_stripe(t_game *game, t_3d *t, int i)
// {
//     t_texture   *tex;
//     int         y;

//     tex = get_wall_texture(game, i);
//     init_strip_cord(game, &ws, i, tex);
    
//     ws.y_step = (float)tex->height / t->projected_wall_height;
//     ws.tex_pos = 0;
    
//     // Handle walls taller than screen
//     if (t->projected_wall_height > WINDOW_HEIGHT)
//         ws.tex_pos = ((t->projected_wall_height - WINDOW_HEIGHT) / 2.0) 
//             * ws.y_step;
    
//     y = t->wall_top_pixel;
//     while (y < t->wall_bottom_pixel)
//     {
//         ws.tex_y = (int)ws.tex_pos;
//         boundaries(&ws, tex);
        
//         ws.color = *(unsigned int *)(tex->addr + (ws.tex_y * tex->line_len
//                     + ws.tex_x * (tex->bpp / 8)));
        
//         my_mlx_pixel_put(game, i, y, ws.color);
//         ws.tex_pos += ws.y_step;
//         y++;
//     }
//}

void boundaries(t_texture *texture, int *x, int *y)
{
    if (*x < 0)
		*x = 0;
    if (*x >= texture->width)
		*x = texture->width - 1;
    if (*y < 0)
		*y = 0;
    if (*y >= texture->height)
		*y = texture->height - 1;
}

void print_wall_line(t_game *game, t_render_3d *render, int x)
{
	t_texture	*texture;
    int 		color;
	float		step;
	int			tex_x;
	int			tex_y;
	int			y;
	float		tex_pos;
	float		wall_x;


	texture  = render->texture;
	if (render->side == 0)
	{
		wall_x = game->player.pos_y + render->perp_wall_dist * render->ray_dir_y;
		//tex_x = fmod(render->map_y, 1);
	}
	else
	{
		// tex_x = fmod(render->map_x, 1);
		wall_x = game->player.pos_x + render->perp_wall_dist * render->ray_dir_x;
	}
	wall_x -= floor(wall_x); 
	tex_x = (int)(wall_x * (float)texture->width);

	step = (float)texture->height / (float)render->line_height;
	tex_pos = 0;
	y = render->draw_start;
	if (render->line_height > HEIGHT)
		tex_pos = ((render->line_height - HEIGHT)/2.0) * step;
	while(y < render->draw_end)
	{
		tex_y = (int)tex_pos;
		boundaries(texture, &tex_x, &tex_y);
		color = *(unsigned int * )(texture->addr + (tex_y * texture->line_length + tex_x * (texture->bits_per_pixel / 8)));
		my_mlx_pixel_put(game->mlx.img, x, y, color);
		tex_pos += step;
		y++;
	}
}

void draw_vertical_line(t_game *game, t_render_3d *render, int x)
{
	int y;
	int m;
	
	y = 0;
	if ((x % 2) == 0)
		m = 0;
	else
		m = 10;
    while (y < render->draw_start - 1)
	{
		if ((m % 20) == 0)
			my_mlx_pixel_put(game->mlx.img, x, y, 0x000000);
		else
			my_mlx_pixel_put(game->mlx.img, x, y, game->textures.ceiling_color);
		m++;
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
void draw_3d(t_game *game, t_render_3d *render, int x)
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