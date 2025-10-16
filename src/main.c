#include "cub3d.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*little))
		return ((char *)big);
	while (big[i] && (i < len))
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j < len) && big[i + j])
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

int init(t_params param, char *map)
{
	if (checkfilenamecub(map) != 0)
		return (printf("Usage: ./cub3d + file.cub"), 1);
	if (parsingcub3d(param, map) != 0)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_params	param;
	
	
	if (argc < 2)
		return (printf(" error: Usage: ./a.out + file.cub"), 1);
	ft_memset(&param, 0, sizeof(t_params));
	if (init(param, argv[1]) != 0)
		return (/*free_everything(param), printf("error"),*/ 1);
	printf("success");
	return (0);


	// printf(BCYAN "\n=============== MAP PARSING TEST ========================" RESET);
	// printf("\n\n");

	// t_map map;
	// (void)argc;
	// if (check_map(argv[1], &map))
	// 	printf(ONRED "ERROR DE MAP" RESET);
	// ft_free_tab((void **)map.map);
	// return 0;
}