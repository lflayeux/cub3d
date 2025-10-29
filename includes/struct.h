/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:48:09 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 16:43:09 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// =============================
// ========= RENDER_3D =========
// =============================

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_texture;

typedef struct s_wall_line
{
	int			color;
	float		step;
	int			tex_x;
	int			tex_y;
	int			y;
	float		tex_pos;
	float		wall_x;
}				t_wall_line;

typedef struct s_render_3d
{
	t_texture	*texture;
	float		camera;
	float		ray_dir_x;
	float		ray_dir_y;
	int			map_x;
	int			map_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		side_dist_x;
	float		side_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	float		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_render_3d;

// =============================
// ============ MAP ============
// =============================

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		n;
	int		s;
	int		w;
	int		e;
	int		player_x;
	int		player_y;
	bool	error;
}			t_map;

// =============================
// ====== COLORS/TEXTURES ======
// =============================

typedef struct s_col_text
{
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;
	int		fcolor;
	int		ccolor;
	char	*no_text;
	char	*so_text;
	char	*ea_text;
	char	*we_text;
	int		nb_color;
	int		nb_text;
	int		nb_line;
	bool	no_fill;
	bool	so_fill;
	bool	ea_fill;
	bool	we_fill;
}			t_col_text;

typedef struct repo_text
{
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	t_texture		north;
	t_texture		south;
	t_texture		west;
	t_texture		east;
}	t_repo_text;

// =============================
// ========== MINILIBX =========
// =============================

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	img;
}			t_mlx;

// =============================
// =========== PLAYER ==========
// =============================

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	ray_x;
	float	ray_y;
}				t_player;

// =============================
// =========== GLOBAL ==========
// =============================

typedef struct s_game
{
	t_map		map;
	t_col_text	col_text;
	t_mlx		mlx;
	t_player	player;
	t_repo_text	textures;
}				t_game;

#endif