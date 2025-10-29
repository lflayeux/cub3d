/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:40:22 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 15:26:53 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int get_color(char *line,int index, int *code)
{
	char colorcode[4];
	int i;

	i = 0;
	ft_memset(colorcode, 0, 4);
	while(line[index] && (line[index] == ' ' || line[index] == '\t')) 
		index++;
	if (!is_size_ok(line, index))
			return (ERROR);
	while (line[index] && line[index] != ',' && line[index] != '\n')
	{
		if (line[index]>= '0' && line[index] <= '9')
		{
			if (i < 3)
			{
				colorcode[i] = line[index];
				i++;
			}
		}
		else if(line[index] != ' ' && line[index] != '\t')
			return (ERROR);
		index++;
	}
	*code = ft_atoi(colorcode);
	if (*code < 0 || *code > 255)
		return (ERROR);
	if (line[index] == ',')
		index++;
	return (index);
}



int fill_color(char *line, char color, t_col_text *col_text)
{
	int i;
	int j;
	int temp_colors[3];
	
	j = 0;
	i = 0;
	if (!is_coma_ok(line))
		return(ERROR);
	if (!is_letter_ok(line))
		return(ERROR);
	while(line[i] && (line[i] == ' ' || line[i] == 'C' || line[i] == 'F'))
		i++;
	while(j<3)
	{
		i = get_color(line, i, &temp_colors[j]);
		if (i ==-1)
			return(ERROR);
		j++;
	}
	if (color == 'F' )
	{
		col_text->fr = temp_colors[0];
		col_text->fg = temp_colors[1];
		col_text->fb = temp_colors[2];
		col_text->fcolor++;
	}
	else if (color == 'C')
	{
		col_text->cr = temp_colors[0];
		col_text->cg = temp_colors[1];
		col_text->cb = temp_colors[2];
		col_text->ccolor++;
	}
	else
		return (ERROR);
	return(SUCCESS);
}


bool    is_color(char *line, t_col_text *col_text)
{
	int i;

	i = 0;
	i = skipspace(line, i);
	if ( line[i] == 'F' || line[i] == 'C')
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
				return(FALSE);
			if (fill_color(line, 'C', col_text) == ERROR)
				return (FALSE);
			return (TRUE);
		}
	}
	return (FALSE);
}
