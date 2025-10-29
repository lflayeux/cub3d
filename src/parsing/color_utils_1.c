/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:12:50 by frene             #+#    #+#             */
/*   Updated: 2025/10/29 16:21:12 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_size_ok(char *line, int index)
{
	int	i;

	i = 0;
	while (line[index] && line[index] != ',' && line[index] != '\n')
	{
		index++;
		if (line[index] != ' ' && line[index] != '\t' )
			i++;
	}
	if (i > 3)
		return (FALSE);
	return (TRUE);
}

bool	is_coma_ok(char *line)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
		return (FALSE);
	return (TRUE);
}

bool	is_letter_ok(char *line)
{
	int	i;
	int	letter;

	letter = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'F' || line[i] == 'C')
			letter++;
		i++;
	}
	if (letter != 1)
		return (FALSE);
	return (TRUE);
}

int	skipspace(char *line, int i)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

int	skip_to_colors(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == 'C' || line[i] == 'F'))
		i++;
	return (i);
}
