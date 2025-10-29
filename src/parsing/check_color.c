/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:40:22 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 16:17:27 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	extract_digits(char *line, int index, char *colorcode, int *i)
{
	while (line[index] && line[index] != ',' && line[index] != '\n')
	{
		if (line[index] >= '0' && line[index] <= '9')
		{
			if (*i < 3)
			{
				colorcode[*i] = line[index];
				(*i)++;
			}
		}
		else if (line[index] != ' ' && line[index] != '\t')
			return (ERROR);
		index++;
	}
	return (index);
}

int	get_color(char *line, int index, int *code)
{
	char	colorcode[4];
	int		i;

	i = 0;
	ft_memset(colorcode, 0, 4);
	index = skipspace(line, index);
	if (!is_size_ok(line, index))
		return (ERROR);
	index = extract_digits(line, index, colorcode, &i);
	if (index == ERROR)
		return (ERROR);
	*code = ft_atoi(colorcode);
	if (validate_color_value(*code) == ERROR)
		return (ERROR);
	if (line[index] == ',')
		index++;
	return (index);
}

int	extract_rgb_values(char *line, int index, int *temp_colors)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		index = get_color(line, index, &temp_colors[j]);
		if (index == ERROR)
			return (ERROR);
		j++;
	}
	return (SUCCESS);
}

int	fill_color(char *line, char color, t_col_text *col_text)
{
	int	index;
	int	j;
	int	temp_colors[3];

	j = 0;
	if (validate_color_format(line) == ERROR)
		return (ERROR);
	index = skip_to_colors(line);
	if (extract_rgb_values(line, index, temp_colors) == ERROR)
		return (ERROR);
	if (color == 'F' )
		assign_floor_color(col_text, temp_colors);
	else if (color == 'C')
		assign_ceiling_color(col_text, temp_colors);
	else
		return (ERROR);
	return (SUCCESS);
}

bool	is_color(char *line, t_col_text *col_text)
{
	int	i;

	i = 0;
	i = skipspace(line, i);
	if (line[i] == 'F' || line[i] == 'C')
	{
		if (line[i] == 'F')
		{
			if (col_text->fcolor != 0)
				return (FALSE);
			if (fill_color(line, 'F', col_text) == ERROR)
				return (FALSE);
			return (TRUE);
		}
		if (line[i] == 'C')
		{
			if (col_text->ccolor != 0)
				return (FALSE);
			if (fill_color(line, 'C', col_text) == ERROR)
				return (FALSE);
			return (TRUE);
		}
	}
	return (FALSE);
}
