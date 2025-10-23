/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:12:25 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/23 16:03:55 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void destroy_mlx(t_game *game)
{
	if (game->mlx.img.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img.img);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.mlx)
	mlx_destroy_display(game->mlx.mlx);
}

void free_game(t_game *game)
{
	if (game == NULL)
		return;
	if (game->map.map)
	{
		ft_free_tab((void **)(game->map.map));
		game->map.map = NULL;
	}
	if (game->col_text.NOtext)
		free(game->col_text.NOtext);
	if (game->col_text.SOtext)
		free(game->col_text.SOtext);
	if (game->col_text.WEtext)
		free(game->col_text.WEtext);
	if (game->col_text.EAtext)
		free(game->col_text.EAtext);
}