/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:11:09 by lflayeux          #+#    #+#             */
/*   Updated: 2025/10/17 17:13:56 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int is_line_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void go_to_map_start(int fd, char **line, t_col_text *col_text)
{
	int i;

	i = 0;
	while (i < col_text->nb_line + 1)
	{
		*line = get_next_line(fd);
		free(*line);
		i++;
	}
	*line = get_next_line(fd);
	while (*line)
	{
		if (is_line_empty(*line) == FALSE)
			return ;
		free(*line);
		*line = get_next_line(fd);
	}
}

void	check_map_char(char c, t_map *map)
{
	if (c != ' ' && c != '\n' && c != 'n' && c != 's' && c != 'w' && c != '0'
		&& c != '1' && c != 'e' && c != 'N' && c != 'S' && c != 'W' && c != 'E')
		map->error = true;
	if (c == 'n' || c == 'N')
		map->n += 1;
	if (c == 's' || c == 'S')
		map->s += 1;
	if (c == 'e' || c == 'E')
		map->e += 1;
	if (c == 'w' || c == 'W')
		map->w += 1;
}

void fill_map_line(char *line, t_map *map, int i)
{
	int j;

	j = 0;
	while (line[j] && line[j] != '\n' && j < map->width)
	{
		check_map_char(line[j], map);
		map->map[i][j] = line[j];
		j++;
	}
	while (j < map->width)
	{
		map->map[i][j] = ' ';
		j++;
	}
}
void reset_gnl(int fd)
{
	char *line;
	while ((line = get_next_line(fd)))
		free(line);
}
