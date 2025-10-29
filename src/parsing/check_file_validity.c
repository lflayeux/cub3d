/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:12:57 by frene             #+#    #+#             */
/*   Updated: 2025/10/29 17:15:04 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_file_cub(char *map)
{
	size_t	len;
	size_t	place;

	len = ft_strlen(map);
	place = len - 4;
	if (ft_strncmp(map + place, ".cub", 4) != 0)
		return (FALSE);
	return (TRUE);
}

int	check_first_elems(t_col_text *col_text, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != 0)
	{
		if (is_color(line, col_text) == TRUE && col_text->nb_text <= 4)
			col_text->nb_color++;
		else if (is_texture(line, col_text) == TRUE && col_text->nb_color <= 2)
			col_text->nb_text++;
		else if (is_line_empty(line) == FALSE
			|| is_color(line, col_text) == TRUE)
			return (free(line), print_parsing_error(COLOR_TEXTURE), ERROR);
		free(line);
		if (col_text->nb_color == 2 && col_text->nb_text == 4)
			break ;
		col_text->nb_line++;
		line = get_next_line(fd);
	}
	if (col_text->nb_color != 2 || col_text->nb_text != 4)
		return (print_parsing_error(COLOR_TEXTURE), ERROR);
	return (SUCCESS);
}

void	color_to_hexa(t_game *game)
{
	t_col_text	*rgb;

	rgb = &game->col_text;
	game->textures.floor_color = (unsigned int)(0 << 24
			| rgb->fr << 16 | rgb->fg << 8 | rgb->fb);
	game->textures.ceiling_color = (unsigned int)(0 << 24
			| rgb->cr << 16 | rgb->cg << 8 | rgb->cb);
}

int	parsing_file_cub(t_game *game, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == ERROR)
		return (print_parsing_error(OPEN_FILE), ERROR);
	if (check_first_elems(&(game->col_text), fd) == ERROR)
		return (ERROR);
	close(fd);
	color_to_hexa(game);
	return (SUCCESS);
}
