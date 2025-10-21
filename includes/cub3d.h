/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:43:54 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/21 16:19:26 by pandemonium      ###   ########.fr       */
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
# define TILE_SIZE 13

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

void init_player(t_params *param);
int init_mlx(t_params *param);
void mini_map(t_params *param);

// =============================
// =========== UTILS ===========
// =============================

void destroy_mlx(t_params *param);
void free_param(t_params *param);



#endif