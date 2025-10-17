/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:13:51 by lflayeux          #+#    #+#             */
/*   Updated: 2025/10/17 15:14:16 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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