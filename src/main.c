/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:46:56 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/23 11:44:27 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// JUSTE POUR LES TESTS A SUPPRIMER APRES
void print_parse_result(t_game *game)
{
	int i;
	int j;

	printf(BCYAN "\n=============== COL_TEXT ========================\n\n" RESET);
	printf("path: %s\n", game->col_text.NOtext );
	printf("path: %s\n", game->col_text.SOtext );
	printf("path: %s\n", game->col_text.WEtext );
	printf("path: %s\n\n", game->col_text.EAtext );
	printf("Fcolor: R%d | G%d | B%d\n", game->col_text.FR, game->col_text.FG, game->col_text.FB);
	printf("Ccolor: R%d | G%d | B%d\n\n", game->col_text.CR, game->col_text.CG, game->col_text.CB);
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

int check_and_init(t_game *game, char *map)
{
	if (is_file_cub(map) == FALSE)
		return (print_parsing_error(OPEN_FILE), ERROR);
	if (parsing_file_cub(game, map) == ERROR)
		return (ERROR);
	if (check_map(map, game) == ERROR)
		return (print_parsing_error(MAP), ERROR);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_game	game;
	
	if (argc < 2)
		return (print_parsing_error(USE), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (check_and_init(&game, argv[1]) == ERROR)
		return (free_game(&game), ERROR);

	// ======= JUSTE POUR LES TESTS A SUPPRIMER APRES ========
	print_parse_result(&game);
	// ===================== MINI MAP =====================================
	if (init_mlx(&game) == ERROR)
		return (destroy_mlx(&game), free_game(&game), ERROR);
	init_player(&game);
	mini_map(&game);
	mlx_put_image_to_window(game.mlx.mlx, game.mlx.win, game.mlx.img.img, 0, 0);
	mlx_loop(game.mlx.mlx);
	destroy_mlx(&game);
	free_game(&game);
	return (SUCCESS);
}

