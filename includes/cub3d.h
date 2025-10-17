/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:43:54 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/17 17:06:40 by frene            ###   ########.fr       */
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

// =============================
// =========== STRUCT ==========
// =============================

# include "struct.h"

// =============================
// =========== INIT ============
// =============================

int			init(t_params *param, char *map);
int			parsingcub3d(t_params *param, char *map);
int			checkfilenamecub(char *map);
int			checkfirstelems(t_col_text *col_text, int fd);

// =============================
// =========== PARSING =========
// =============================

# include "parsing.h"

// =============================
// =========== UTILS ===========
// =============================





#endif