/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:26:01 by lflayeux          #+#    #+#             */
/*   Updated: 2025/10/20 11:53:47 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void flood_fill(t_map *map, int x, int y, bool **visited)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
	{
		map->error = true;
		return ;
	}
	if (map->map[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = true;
	flood_fill(map, x + 1, y, visited);
	flood_fill(map, x - 1, y, visited);
	flood_fill(map, x, y + 1, visited);
	flood_fill(map, x, y - 1, visited);
}

void	get_player_position(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' ||
				map->map[i][j] == 'E' || map->map[i][j] == 'W' ||
				map->map[i][j] == 'n' || map->map[i][j] == 's' ||
				map->map[i][j] == 'e' || map->map[i][j] == 'w')
			{
				map->player_x = j;
				map->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_free_bool(bool **to_free, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(to_free[i]);
		i++;
	}	
	free(to_free);
}

int is_map_closed(t_map *map)
{
	bool **visited;
	int i;
	
	get_player_position(map);
	visited = ft_calloc(map->height, sizeof(bool *));
	if (!visited)
		return (FALSE);
	i = 0;
	while (i < map->height)
	{
		visited[i] = ft_calloc(map->width, sizeof(bool));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			return (free(visited), FALSE);
		}
		i++;
	}
	flood_fill(map, map->player_x, map->player_y, visited);
	ft_free_bool(visited, map->height);
	if (map->error == true)
		return (FALSE);
	return (TRUE);
}
