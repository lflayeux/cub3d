/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:28:58 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/17 17:13:30 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void stock_map(int fd, t_map *map, t_col_text *col_text)
{
	char *line;
	int i;

	(void)map;
	line = NULL;
	i = 0;
	go_to_map_start(fd, &line, col_text);
	while (line && i < map->height)
	{
		if (is_line_empty(line) == TRUE)
			return (free(line));
		fill_map_line(line, map, i);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}
// Peut etre le mettre dans init et pas dans check
// check map utils
void get_height_and_width(int fd, t_map *map, t_col_text *col_text)
{
	int width;
	int height;
	char *line;

	width = 0;
	height = 0;
	line = NULL;
	go_to_map_start(fd, &line, col_text);
	while (line)
	{
		if (is_line_empty(line) == FALSE)
		{
			height++;
			if ((int)ft_strlen(line) > width)
				width = ft_strlen(line);
		}
		else
			break;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->height = height;
	map->width = width;
	printf("height => %d\nwidth => %d\n", map->height, map->width);
}

void print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == ' ')
				printf(".");
			else
				printf("%c", map->map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
int is_map_valid(t_map *map)
{
	if (map->error == true)
		return (FALSE);
	if (map->n == 0 && map->s == 0 && map->w == 0 && map->e == 0)
		return (FALSE);
	if (map->n == 1 && (map->s == 1 || map->w == 1 || map->e == 1))
		return (FALSE);
	if (map->s == 1 && (map->n == 1 || map->w == 1 || map->e == 1))
		return (FALSE);
	if (map->w == 1 && (map->s == 1 || map->n == 1 || map->e == 1))
		return (FALSE);
	if (map->e == 1 && (map->s == 1 || map->w == 1 || map->n == 1))
		return (FALSE);
	if (map->n > 1 || map->s > 1 || map->e > 1 || map->w > 1)
		return (FALSE);
	return (TRUE);
}

// void is_map_closed(t_map *map)
// {
	


// }

int check_map(char *file, t_params *param)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (ERROR);
	}
	printf("check_map: %s\n", file);
	get_height_and_width(fd, &(param->map), &(param->col_text));
	reset_gnl(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (ERROR);
	}
	if (init_map(&(param->map)) == ERROR)
		return (ERROR);
	stock_map(fd, &(param->map), &(param->col_text));
	reset_gnl(fd);
	close(fd);
	// is_map_closed(map);
	print_map(&(param->map));
	// printf("map->n %d\n", map->n);
	// printf("map->s %d\n", map->s);
	// printf("map->e %d\n", map->e);
	// printf("map->w %d\n", map->w);
	// printf("map->error %d\n", map->error);
	if (is_map_valid(&(param->map)) == ERROR)
		return (ft_free_tab((void **)param->map.map), ERROR);
	return (SUCCESS);
}
