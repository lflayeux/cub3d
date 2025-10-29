/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:46:56 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 17:38:34 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// JUSTE POUR LES TESTS A SUPPRIMER APRES
void	print_parse_result(t_game *game)
{
	int	i;
	int	j;

	printf(BCYAN "\n=============== COL_TEXT ========================\n\n" RESET);
	printf("path: %s\n", game->col_text.no_text);
	printf("path: %s\n", game->col_text.so_text);
	printf("path: %s\n", game->col_text.we_text);
	printf("path: %s\n\n", game->col_text.ea_text);
	printf("Fcolor: R%d | G%d | B%d\n", game->col_text.fr,
		game->col_text.fg, game->col_text.fb);
	printf("Ccolor: R%d | G%d | B%d\n\n", game->col_text.cr,
		game->col_text.cg, game->col_text.cb);
	printf(BCYAN "\n=============== MAP ========================\n\n" RESET);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			printf("%c", game->map.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

int	check_and_init(t_game *game, char *map)
{
	// to do: ajout d'un print error parse
	if (is_file_cub(map) == FALSE)
		return (print_parsing_error(OPEN_FILE), ERROR);
	if (parsing_file_cub(game, map) == ERROR)
		return (ERROR);
	if (check_map(map, game) == ERROR)
		return (print_parsing_error(MAP), ERROR);
	if (init_mlx(game) == ERROR)
		return (destroy_mlx(game), ERROR);
	if (load_textures(game) == ERROR)
		return (destroy_mlx(game), ERROR);
	init_player(game);
	return (SUCCESS);
}

void	cub3d_game(t_game *game)
{
	render_3d(game);
	mini_map(game);
}

int	game_loop(t_game *game)
{
	if (game->mlx.img.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img.img);
	game->mlx.img.img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	if (!game->mlx.img.img)
		return (ERROR);
	game->mlx.img.addr = mlx_get_data_addr(game->mlx.img.img,
			&game->mlx.img.bits_per_pixel, &game->mlx.img.line_length,
			&game->mlx.img.endian);
	if (!game->mlx.img.addr)
		return (ERROR);
	cub3d_game(game);
	mlx_put_image_to_window(game->mlx.mlx,
		game->mlx.win, game->mlx.img.img, 0, 0);
	setup_hooks(game);
	mlx_loop(game->mlx.mlx);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (print_parsing_error(USE), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (check_and_init(&game, argv[1]) == ERROR)
		return (free_game(&game), ERROR);
// ======= JUSTE POUR LES TESTS A SUPPRIMER APRES ========
	print_parse_result(&game);
// ===================== GAME =====================================
	game_loop(&game);
	destroy_mlx(&game);
	free_game(&game);
	return (SUCCESS);
}
