#include "cub3d.h"
//------------------------------------------
//exemple .cub

// NO ./path_to_the_north_texture
// SO ./path_to_the_south_texture
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture
//
// F 220,100,0
// C 225,30,0
//
//         1111111111111111111111111
//         1000000000110000000000001
//         1011000001110000000000001
//         1001000000000000000000001
// 111111111011000001110000000000001
// 100000000011000001110111111111111
// 11110111111111011100000010001
// 11110111  1111011101010010001111
// 110000001101010111000000100011 1
// 10000000000000001100000010001111
// 10000000000000001101010010001
// 11000001110101011111011110N0111
// 11110111 1110101 101111010001
// 11111111 1111111 111111111111

//------------------------------------------------

//Textures
	// NO ./path_to_north_texture
	// SO ./path_to_south_texture
	// WE ./path_to_west_texture
	// EA ./path_to_east_texture

//colours
	// F R,G,B (F for Floor)
	// C R,G,B (C for Ceiling) :warning: with RGB an integer between 0 and 255

//Maps


// If map is not closed / contains invalid characters → error.
//( can we have 0 behind the wall?)
//check map filled strictly with 



// ⚠️ If any problem occurs, the program should exit and print Error\n followed by a descriptive error message.

// If RGB values are out of range or not integers → error.

// If the .cub file cannot be opened → error.

// If there are duplicate identifiers → error.

// check map .cub

//check map closed with 1 

//what to do:
// 1st check filename 

// 2nd/3rd check textures (could be optional and be first or second independantly)
//  - each element can be separated by one or more spaces 
//  - North textures: NO ./"path_to_the_north_texture"
//  - South textures: SO ./"path_to_the_south_texture"
//  - West textures: WE ./"path_to_the_west_texture"
//  - East textures: EA ./"path_to_the_east_texture"
//  - if no information should have base setup
//  - n'importe quelle couleur peut etre premiere

// 2nd/3rd check colours (could be optional and be first or second independantly)
//  - each element can be separated by one or more spaces 
//  - Color range must be from 0 to 255
//  - Floor color : F 220,100,0
//  - Ceiling color: C 225,30,0
//  - without information should be set up to the base color

// 4th check maps (not optional)
//  - Map must be closed (could be 1 or 0 behind the wall )
//  - Map must be composed only with those char 1 || 0  && 1 * N || S || E || W  (can't contain more than one of those above)
//  - spaces should be handled to make the proper map correct (the char inside the wall cannot be filled with a space, only outside of the wall)

//struct png
// int textures = 0;
// int color = 0;

//faire la struct commencer le main, et les structs plus faire le parsing cub et le init



int checkfilenamecub(char *map)
{
	size_t len;
	size_t place;

	len = strlen(map);
	place = len - 4;
	if (ft_strncmp(map+place, ".cub", 4) != 0)
		return (1);
	return (0);
}

int parsingcub3d(t_params param, char *map)
{
	int fd;

	fd = open(map,O_RDONLY);
	if (fd == -1)
		return (printf("error opening file"), 1);
	if (checkfirstelems(param.col_text, fd)!= 0)
		return (1);
	//checkmap(png, fd);

	return (0);
}

//------

int checkfirstelems(t_col_text col_text, int fd)
{
	char *line;
	int color;
	int textures;

	color = 0;
	textures = 0;
	line = get_next_line(fd);
	while(line != 0)
	{
		//si color == 1 on doit s'assurer que la ligne suivante soit aussi une couleur
		if (is_color(line, col_text)== 0)
		{
			if (textures > 0 && textures < 4)
				return(free(line), printf("error parameter are not written correctly"), 1);
			color++;
		}
		//si texture n'est pas egale a 0 ou 4, la ligne suivante doit etre une texture obligatoirement
		else if (is_textures(line, col_text) == 0)
		{
			if (color == 1)
				return (free(line), printf("error parameter are not written correctly"),1);
			textures++;
		}
		// else
		// 	return(printf("error wrong parameter"), 1);
		free(line);
		if (color ==2 && textures == 4)
			break;
		line = get_next_line(fd);
	}
	if (color != 2 || textures != 4)
		return(printf("error: the color or textures are not fully written"), 1);
	return(0);
}

