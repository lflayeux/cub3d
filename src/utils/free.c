/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:12:25 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 17:40:12 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_all_textures(t_game *game)
{
	if (game->textures.north.img)
	{
		mlx_destroy_image(game->mlx.mlx, game->textures.north.img);
		game->textures.north.img = NULL;
	}
	if (game->textures.south.img)
	{
		mlx_destroy_image(game->mlx.mlx, game->textures.south.img);
		game->textures.south.img = NULL;
	}
	if (game->textures.west.img)
	{
		mlx_destroy_image(game->mlx.mlx, game->textures.west.img);
		game->textures.west.img = NULL;
	}
	if (game->textures.east.img)
	{
		mlx_destroy_image(game->mlx.mlx, game->textures.east.img);
		game->textures.east.img = NULL;
	}
}

void	destroy_mlx(t_game *game)
{
	destroy_all_textures(game);
	if (game->mlx.img.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img.img);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.mlx)
	{
		mlx_destroy_display(game->mlx.mlx);
		free(game->mlx.mlx);
	}
}

void	free_game(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->map.map)
	{
		ft_free_tab((void **)(game->map.map));
		game->map.map = NULL;
	}
	if (game->col_text.no_text)
		free(game->col_text.no_text);
	if (game->col_text.so_text)
		free(game->col_text.so_text);
	if (game->col_text.we_text)
		free(game->col_text.we_text);
	if (game->col_text.ea_text)
		free(game->col_text.ea_text);
}
