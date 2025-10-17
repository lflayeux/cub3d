/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:43:16 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/17 15:13:51 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "struct.h"

// =============================
// =========== COLORS ==========
// =============================

bool		is_color(char *line, t_col_text *col_text);
int			fill_color(char *line, char color, t_col_text *col_text);
int			get_color(char *line,int index, int *code);

// =============================
// ========== TEXTURES =========
// =============================

bool		is_textures(char *line, t_col_text *col_text);
int			fill_textures(char *line, char *name, t_col_text *col_text);
int			get_texture(char *line, char **texture);
bool		is_texture_ok(char *texture);

// =============================
// ============ MAP ============
// =============================

int	check_map();

#endif