/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:48:09 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/22 15:43:23 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// =============================
// ============ MAP ============
// =============================

typedef struct s_map
{
	char **map;
	int width;
	int height;
	int	n;
	int s;
	int w;
	int e;
	int player_x;
	int player_y;
	bool error;
}				t_map;

// =============================
// ====== COLORS/TEXTURES ======
// =============================

typedef struct s_col_text
{
	//code RGB
	int		FR;
	int		FG;
	int		FB;
	int		CR;
	int		CG;
	int		CB;
	// bool check
	int		Fcolor;
	int		Ccolor;
	//Texture name
	char *NOtext;
	char *SOtext;
	char *EAtext;
	char *WEtext;
	int nb_color;
	int nb_text;
	int nb_line;
} t_col_text;

// =============================
// ========== MINILIBX =========
// =============================

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	img;
}				t_mlx;


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

typedef struct	s_params
{
	t_map		map;
	t_col_text	col_text;
	t_mlx		mlx;
	t_player	player;
} t_params;

# endif