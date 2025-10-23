/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:43:16 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/23 11:44:27 by pandemonium      ###   ########.fr       */
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

// =============================
// ====== COLORS UTILS =========
// =============================

bool		is_coma_ok(char *line);
bool		is_size_ok(char *line, int index);
bool		is_letter_ok(char *line);
int			skipspace(char *line, int i);

// =============================
// ========== TEXTURES =========
// =============================

bool		is_texture(char *line, t_col_text *col_text);
bool		is_texture_ok(char *texture);

// =============================
// ============ MAP ============
// =============================

int check_map(char *file, t_game *game);
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

int			init(t_game *game, char *map);
int			parsing_file_cub(t_game *game, char *map);
int			is_file_cub(char *map);

#endif