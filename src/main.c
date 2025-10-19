#include "cub3d.h"

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

int main(int argc, char **argv)
{
	t_params	param;
	
	if (argc < 2)
		return (print_parsing_error(USE), 1);
	ft_memset(&param, 0, sizeof(t_params));
	if (check_and_init(&param, argv[1]) == ERROR)
		return (ERROR);
	print_parse_result(&param);
	// ft_free_tab((void **)(param.map.map));
	return (SUCCESS);
}