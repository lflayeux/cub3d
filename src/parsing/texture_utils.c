/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:48:48 by frene             #+#    #+#             */
/*   Updated: 2025/10/29 17:08:02 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_texture_ok(char *texture)
{
	int	fd;
	int	len;

	if (!texture)
		return (FALSE);
	len = strlen(texture);
	if (len < 4)
		return (FALSE);
	if (strcmp(texture + len - 4, ".xpm") != 0)
		return (FALSE);
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

int	find_texture_start(char *line)
{
	int	i;

	i = 0;
	i = skipspace(line, i);
	while (line[i] && (line[i] != ' ' && line[i] != '\t'))
		i++;
	i = skipspace(line, i);
	return (i);
}

int	calculate_texture_length(char *line, int index)
{
	int	start;

	start = index;
	while (line[index] && line[index] != '\n' && line[index] != '\r')
		index++;
	return (index - start);
}

char	*allocate_and_copy(char *line, int index, int len)
{
	char	*texture;
	int		y;

	y = 0;
	texture = malloc(len + 1);
	if (!(texture))
		return (NULL);
	while (y < len)
	{
		texture[y] = line[index + y];
		y++;
	}
	texture[y] = '\0';
	return (texture);
}
