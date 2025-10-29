#include "cub3d.h"


int	load_single_texture(void *mlx, char *path, t_texture *texture)
{
	texture->width = TEXT_WIDTH;
	texture->height = TEXT_HEIGHT;
	if (!path || !texture)
		return (ERROR);
	texture->img = mlx_xpm_file_to_image(mlx, path, &texture->width, &texture->height);
	if (!texture->img)
		return (ERROR);
	texture->addr = mlx_get_data_addr( texture->img, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!texture->addr)
		return (ERROR);
	return (printf("one texture is correctly loaded\n"),SUCCESS);
}

int load_textures(t_game *game)
{
	if (load_single_texture(game->mlx.mlx, game->col_text.no_text, &game->textures.north) == ERROR)
		return (ERROR);
	if (load_single_texture(game->mlx.mlx, game->col_text.so_text, &game->textures.south)== ERROR)
		return (ERROR);
	if (load_single_texture(game->mlx.mlx, game->col_text.we_text, &game->textures.west)== ERROR)
		return (ERROR);
	if (load_single_texture(game->mlx.mlx, game->col_text.ea_text, &game->textures.east)== ERROR)
		return (ERROR);
	return (printf("all the texture were correctly loaded\n"),SUCCESS);
}