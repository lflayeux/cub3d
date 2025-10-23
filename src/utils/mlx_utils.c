/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:32:59 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/23 17:46:01 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return;
	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int game_loop(t_game *game)
{
	if (game->mlx.img.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img.img);
	game->mlx.img.img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	if (!game->mlx.img.img)
		return (ERROR);
	game->mlx.img.addr = mlx_get_data_addr(game->mlx.img.img, &game->mlx.img.bits_per_pixel, &game->mlx.img.line_length,&game->mlx.img.endian);
	if (!game->mlx.img.addr)
		return (ERROR);
	mini_map(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img.img, 0, 0);
	setup_hooks(game);
	mlx_loop(game->mlx.mlx);
	return (SUCCESS);
}