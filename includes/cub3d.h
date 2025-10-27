/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:43:54 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/27 14:08:57 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// =============================
// ========== LIBRARIES ========
// =============================

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <math.h>
# include <string.h>
#include "../minilibx/mlx.h"

// =============================
// =========== LIBFT ===========
// =============================

# include "../libft/libft.h"

// =============================
// ========== COLORS ===========
// =============================

# include "colors.h"

// =============================
// ======== MAGIC NUMBER =======
// =============================

# define ERROR -1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define TILE_SIZE 15
# define FOV 66
# define M_PI 3.14159265358979323846
# define WIDTH 1920
# define HEIGHT 1080
# define W 0x77
# define A 0x61
# define S 0x73
# define D 0x64
# define LEFT_ARROW 0xff51
# define RIGHT_ARROW 0xff53
# define MOVE_SPEED 0.2
# define COLLISION_MARGIN 0.1
# define TEXT_WIDTH 64
# define TEXT_HEIGHT 64


enum parsing_error
{
	USE,
	OPEN_FILE,
	COLOR_TEXTURE,
	MAP,
};

// =============================
// =========== STRUCT ==========
// =============================

# include "struct.h"

// =============================
// =========== PARSING =========
// =============================

# include "parsing.h"

// =============================
// ============ GAME ===========
// =============================

# include "game.h"

// =============================
// =========== UTILS ===========
// =============================
int		init_mlx(t_game *game);
void	destroy_mlx(t_game *game);
void	free_game(t_game *game);
void	setup_hooks(t_game *game);


#endif