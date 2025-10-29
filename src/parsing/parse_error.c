/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:58:59 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 18:47:59 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_use_error(void)
{
	printf(ONRED "\nError: USAGE: ./cub3d + file.cub" RESET);
	printf("\n\nThe .cub file must contain:\n");
	printf("- 4 texture paths (NO, SO, WE, EA)\n");
	printf("- 2 colors (F for Floor, C for Ceiling)\n");
	printf("- A valid map\n");
}

void	print_file_error(void)
{
	printf(ONRED "\nError: OPENING FILE" RESET);
	printf("\n\nPlease check if the file exists and is accessible.\n");
}

void	print_col_text_error(void)
{
	printf(ONRED "\nError: COLOR/TEXTURE PARAMETERS" RESET);
	printf(BRED "\n\nColor must be formatted like this:\n");
	printf("- F R,G,B (F for Floor)\n");
	printf("- C R,G,B (C for Ceiling)\n");
	printf("with R, G, B being integers between 0 and 255.\n\n");
	printf("Texture paths must be formatted like this:\n");
	printf("- NO ./path_to_the_north_texture\n");
	printf("- SO ./path_to_the_south_texture\n");
	printf("- WE ./path_to_the_west_texture\n");
	printf("- EA ./path_to_the_east_texture\n");
	printf("- xpm files must be valid!\n");
	printf("Only .xpm files are accepted for textures.\n" RESET);
}

void	print_map_error(void)
{
	printf(ONRED "\nError: MAP" RESET);
	printf("\n\nThe map must be closed and only contain valid characters:\n");
	printf("- '1' for walls\n");
	printf("- '0' for empty spaces\n");
	printf("- 'N', 'S', 'E', 'W' for player start positions\n");
	printf("Ensure there is exactly one player start position.\n" RESET);
}

void	print_parsing_error(enum e_parsing_error error_type)
{
	if (error_type == USE)
		print_use_error();
	else if (error_type == OPEN_FILE)
		print_file_error();
	else if (error_type == COLOR_TEXTURE)
		print_col_text_error();
	else if (error_type == MAP)
		print_map_error();
}
