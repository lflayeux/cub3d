/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:43:16 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 17:05:40 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "struct.h"

// =============================
// =========== ERROR ===========
// =============================

void		print_parsing_error(enum e_parsing_error error_type);

// =============================
// =========== COLORS ==========
// =============================

bool		is_color(char *line, t_col_text *col_text);

// =============================
// ====== COLORS UTILS =========
// =============================

bool		is_coma_ok(char *line);
bool		is_size_ok(char *line, int index);
bool		is_letter_ok(char *line);
int			skipspace(char *line, int i);
int			skip_to_colors(char *line);
int			validate_color_format(char *line);
void		assign_ceiling_color(t_col_text *col_text, int *temp_colors);
void		assign_floor_color(t_col_text *col_text, int *temp_colors);
int			validate_color_value(int code);

// =============================
// ====== TEXTURE UTILS ========
// =============================

bool		is_texture_ok(char *texture);
int			find_texture_start(char *line);
int			calculate_texture_length(char *line, int index);
char		*allocate_and_copy(char *line, int index, int len);

// =============================
// ========== TEXTURES =========
// =============================

int			load_textures(t_game *game);
bool		is_texture(char *line, t_col_text *col_text);

// =============================
// ============ MAP ============
// =============================

int			check_map(char *file, t_game *game);
int			is_line_empty(char *line);
void		go_to_map_start(int fd, char **line, t_col_text *col_text);
void		check_map_char(char c, t_map *map);
void		fill_map_line(char *line, t_map *map, int i);
void		reset_gnl(int fd);

int			is_map_closed(t_map *map);
int			init_map(t_map *map);

// =============================
// =========== INIT ============
// =============================

int			init(t_game *game, char *map);
int			parsing_file_cub(t_game *game, char *map);
int			is_file_cub(char *map);

#endif