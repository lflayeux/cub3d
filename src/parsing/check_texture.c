/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:27:20 by frene             #+#    #+#             */
/*   Updated: 2025/10/29 17:07:35 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture(char *line, char **texture)
{
	int	index;
	int	len;
	int	y;

	y = 0;
	index = 0;
	index = find_texture_start(line);
	len = calculate_texture_length(line, index);
	*texture = allocate_and_copy(line, index, len);
	if (!(texture))
		return (ERROR);
	if (is_texture_ok(*texture) == FALSE)
	{
		free(*texture);
		*texture = NULL;
		return (ERROR);
	}
	return (SUCCESS);
}

static bool	check_texture_name(char *line)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i + y] && (line[i + y] != ' ' && line[i + y] != '\t'))
		y++;
	if (y > 2)
		return (FALSE);
	return (TRUE);
}

static int	handle_texture_type(char *line, char *name, t_col_text *col_text)
{
	int	result;

	if (strcmp(name, "NO") == 0 && col_text->no_fill != TRUE)
	{
		result = get_texture(line, &(col_text->no_text));
		col_text->no_fill = TRUE;
	}
	else if (strcmp(name, "SO") == 0 && col_text->so_fill != TRUE)
	{
		result = get_texture(line, &(col_text->so_text));
		col_text->so_fill = TRUE;
	}
	else if (strcmp(name, "EA") == 0 && col_text->ea_fill != TRUE)
	{
		result = get_texture(line, &(col_text->ea_text));
		col_text->ea_fill = TRUE;
	}
	else if (strcmp(name, "WE") == 0 && col_text->we_fill != TRUE)
	{
		result = get_texture(line, &(col_text->we_text));
		col_text->we_fill = TRUE;
	}
	else
		return (ERROR);
	return (result);
}

static int	fill_textures(char *line, char *name, t_col_text *col_text)
{
	if (!check_texture_name(line))
		return (ERROR);
	return (handle_texture_type(line, name, col_text));
}

bool	is_texture(char *line, t_col_text *col_text)
{
	int		i;
	int		y;
	char	name[3];

	i = 0;
	y = 0;
	i = skipspace(line, i);
	while (line[i] && line[i] != ' ' && line[i] != '\t' && y < 2)
	{
		name[y] = line[i];
		y++;
		i++;
	}
	name[y] = '\0';
	if (y == 2)
	{
		if (fill_textures(line, name, col_text) == ERROR)
			return (FALSE);
		return (TRUE);
	}
	else
		return (FALSE);
	return (TRUE);
}
