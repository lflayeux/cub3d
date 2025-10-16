/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:48:09 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/16 18:52:21 by pandemonium      ###   ########.fr       */
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

// =============================
// =========== GLOBAL ==========
// =============================

typedef struct	s_params
{
	t_map	map;
	t_col_text	col_text;
} t_params;

# endif