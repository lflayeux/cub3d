/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:28:58 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/16 18:56:16 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// check map utils
int is_line_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
// check map utils
void go_to_map_start(int fd, char **line)
{
	while ((*line = get_next_line(fd)))
	{
		if (is_line_empty(*line) == ERROR)
			return ;
		free(*line);
	}
}
// check map utils
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

void stock_map(int fd, t_map *map)
{
	char *line;
	int i;

	(void)map;
	line = NULL;
	i = 0;
	go_to_map_start(fd, &line);
	while (line && i < map->height)
	{
		if (is_line_empty(line) == SUCCESS)
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
void get_height_and_width(int fd, t_map *map)
{
	int width;
	int height;
	char *line;

	width = 0;
	height = 0;
	line = NULL;
	go_to_map_start(fd, &line);
	while (line)
	{
		if (is_line_empty(line) == ERROR)
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
int init_map(t_map *map)
{
	int i;

	i = 0;
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	if (map->map == NULL)
		return (ERROR);
	while (i < map->height)
	{
		map->map[i] = ft_calloc(map->width + 1, sizeof(char));
		if (!map->map[i])
		{
			while (--i >= 0)
				free(map->map[i]);
			return (free(map), ERROR);
		}
		i++;
	}
	map->n = 0;
	map->s = 0;
	map->w = 0;
	map->e = 0;
	map->error = false;
	return (SUCCESS);
}
// check map utils
void reset_gnl(int fd)
{
	char *line;
	while ((line = get_next_line(fd)))
		free(line);
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
		return (ERROR);
	if (map->n == 0 && map->s == 0 && map->w == 0 && map->e == 0)
		return (ERROR);
	if (map->n == 1 && (map->s == 1 || map->w == 1 || map->e == 1))
		return (ERROR);
	if (map->s == 1 && (map->n == 1 || map->w == 1 || map->e == 1))
		return (ERROR);
	if (map->w == 1 && (map->s == 1 || map->n == 1 || map->e == 1))
		return (ERROR);
	if (map->e == 1 && (map->s == 1 || map->w == 1 || map->n == 1))
		return (ERROR);
	if (map->n > 1 || map->s > 1 || map->e > 1 || map->w > 1)
		return (ERROR);
	return (SUCCESS);
}

// void is_map_closed(t_map *map)
// {
	


// }

int check_map(char *file, t_map *map)
{
	int fd;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (ERROR);
	}
	printf("check_map: %s\n", file);
	get_height_and_width(fd, map);
	reset_gnl(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (ERROR);
	}
	if (init_map(map) == ERROR)
		return (ERROR);
	stock_map(fd, map);
	reset_gnl(fd);
	close(fd);
	// is_map_closed(map);
	print_map(map);
	// printf("map->n %d\n", map->n);
	// printf("map->s %d\n", map->s);
	// printf("map->e %d\n", map->e);
	// printf("map->w %d\n", map->w);
	// printf("map->error %d\n", map->error);
	if (is_map_valid(map) == ERROR)
		return (ft_free_tab((void **)map->map), ERROR);
	return (SUCCESS);
}
