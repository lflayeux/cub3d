/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:12:25 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/21 16:23:30 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void destroy_mlx(t_params *param)
{
	if (param->mlx.img.img)
		mlx_destroy_image(param->mlx.mlx, param->mlx.img.img);
	if (param->mlx.win)
		mlx_destroy_window(param->mlx.mlx, param->mlx.win);
}

void free_param(t_params *param)
{
	if (param == NULL)
		return;
	if (param->map.map)
	{
		ft_free_tab((void **)(param->map.map));
		param->map.map = NULL;
	}
	if (param->col_text.NOtext)
		free(param->col_text.NOtext);
	if (param->col_text.SOtext)
		free(param->col_text.SOtext);
	if (param->col_text.WEtext)
		free(param->col_text.WEtext);
	if (param->col_text.EAtext)
		free(param->col_text.EAtext);
}