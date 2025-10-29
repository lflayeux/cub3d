/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:07:57 by frene             #+#    #+#             */
/*   Updated: 2025/10/29 16:21:26 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_floor_color(t_col_text *col_text, int *temp_colors)
{
	col_text->fr = temp_colors[0];
	col_text->fg = temp_colors[1];
	col_text->fb = temp_colors[2];
	col_text->fcolor++;
}

void	assign_ceiling_color(t_col_text *col_text, int *temp_colors)
{
	col_text->cr = temp_colors[0];
	col_text->cg = temp_colors[1];
	col_text->cb = temp_colors[2];
	col_text->ccolor++;
}

int	validate_color_format(char *line)
{
	if (!is_coma_ok(line))
		return (ERROR);
	if (!is_letter_ok(line))
		return (ERROR);
	return (SUCCESS);
}

int	validate_color_value(int code)
{
	if (code < 0 || code > 255)
		return (ERROR);
	return (SUCCESS);
}
