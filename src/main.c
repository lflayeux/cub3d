#include "cub3d.h"

// JUSTE POUR LES TESTS A SUPPRIMER APRES
void print_parse_result(t_params *param)
{
	int i;
	int j;

	printf(BCYAN "\n=============== COL_TEXT ========================\n\n" RESET);
	printf("path: %s\n", param->col_text.NOtext );
	printf("path: %s\n", param->col_text.SOtext );
	printf("path: %s\n", param->col_text.WEtext );
	printf("path: %s\n\n", param->col_text.EAtext );
	printf("Fcolor: R%d | G%d | B%d\n", param->col_text.FR, param->col_text.FG, param->col_text.FB);
	printf("Ccolor: R%d | G%d | B%d\n\n", param->col_text.CR, param->col_text.CG, param->col_text.CB);
	printf(BCYAN "\n=============== MAP ========================\n\n" RESET);
	i = 0;
	while (i < param->map.height)
	{
		j = 0;
		while (j < param->map.width)
		{
			printf("%c", param->map.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

int check_and_init(t_params *param, char *map)
{
	if (is_file_cub(map) == FALSE)
		return (print_parsing_error(OPEN_FILE), ERROR);
	if (parsing_file_cub(param, map) == ERROR)
		return (ERROR);
	if (check_map(map, param) == ERROR)
		return (print_parsing_error(MAP), ERROR);
	return (SUCCESS);
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


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(/*int argc, char **argv*/void)
{
	// t_params	param;
	
	// if (argc < 2)
	// 	return (print_parsing_error(USE), 1);
	// ft_memset(&param, 0, sizeof(t_params));
	// if (check_and_init(&param, argv[1]) == ERROR)
	// 	return (free_param(&param), ERROR);
	// // JUSTE POUR LES TESTS A SUPPRIMER APRES
	// print_parse_result(&param);
	// free_param(&param);
	// ft_free_tab((void **)(param.map.map));
	void *mlx;
	void *mlx_win;
	// t_data	img;
	void *xpm;
	int xpm_width;
	int xpm_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920,1080, "hello word");
	
	
	

	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	// my_mlx_pixel_put(&img, 200, 200, 0x00FF0000);
	xpm = mlx_xpm_file_to_image(mlx, "./texture/texture2.xpm", &xpm_width, &xpm_height);
	mlx_put_image_to_window(mlx, mlx_win,xpm, 0, 0);
	mlx_loop(mlx);
	return (SUCCESS);
}

