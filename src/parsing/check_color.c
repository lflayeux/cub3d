/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:40:22 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/19 21:05:55 by pandemonium      ###   ########.fr       */
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
			if (i<3)
			{
				colorcode[i] = line[index];
				i++;
			}
		}
		else if(line[index] != ' ')
			return (ERROR);
		index++;
	}
	*code = atoi(colorcode);
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
		col_text->FR = temp_colors[0];
		col_text->FG = temp_colors[1];
		col_text->FB = temp_colors[2];
		col_text->Fcolor++;
	}
	else if (color == 'C')
	{
		col_text->CR = temp_colors[0];
		col_text->CG = temp_colors[1];
		col_text->CB = temp_colors[2];
		col_text->Ccolor++;
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
			if (col_text->Fcolor != 0)
				return (FALSE);
			if (fill_color(line, 'F', col_text) == ERROR)
				return (FALSE);
			return (TRUE);
		}
		if (line[i] == 'C')
		{
			if (col_text->Ccolor != 0)
				return(FALSE);
			if (fill_color(line, 'C', col_text) == ERROR)
				return (FALSE);
			return (TRUE);
		}
	}
	// else if( line[i] != "F" || line[i] != "C" || line[i] != " ")
	//     return (printf("Error wrong parameter for color"),1);
	return (FALSE);
}