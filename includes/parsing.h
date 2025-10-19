/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:43:16 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/19 19:16:29 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "struct.h"

// =============================
// =========== ERROR ===========
// =============================

void print_parsing_error(enum parsing_error error_type);

// =============================
// =========== COLORS ==========
// =============================

bool		is_color(char *line, t_col_text *col_text);
int			fill_color(char *line, char color, t_col_text *col_text);
int			get_color(char *line,int index, int *code);

// =============================
// ====== COLORS UTILS =========
// =============================

bool		is_coma_ok(char *line);
bool		is_size_ok(char *line, int index);
int			skipspace(char *line, int i);

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

int check_map(char *file, t_params *param);
int is_line_empty(char *line);
void go_to_map_start(int fd, char **line, t_col_text *col_text);
void	check_map_char(char c, t_map *map);
void fill_map_line(char *line, t_map *map, int i);
void reset_gnl(int fd);

int is_map_closed(t_map *map);
int init_map(t_map *map);

// =============================
// =========== INIT ============
// =============================

int			init(t_params *param, char *map);
int			parsing_file_cub(t_params *param, char *map);
int			is_file_cub(char *map);

#endif