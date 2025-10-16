#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <math.h>
# include <string.h>
# include "../libft/libft.h"

# define ERROR -1
# define SUCCESS 0

typedef struct s_map
{
	char **map;
	int width;
	int height;
	int	n;
	int s;
	int w;
	int e;
	bool error;
}				t_map;

typedef struct s_col_text
{
	//code RGB
	int		FR;
	int		FG;
	int		FB;
	int		CR;
	int		CG;
	int		CB;
	// bool check
	int		Fcolor;
	int		Ccolor;
	//Texture name
	char *NOtext;
	char *SOtext;
	char *EAtext;
	char *WEtext;
} t_col_text;

typedef struct	s_params
{
	t_map	map;
	t_col_text	col_text;
} t_params;

/* MAIN */
int			main(int argc, char **argv);


/* INIT */
int			init(t_params param, char *map);
int			parsingcub3d(t_params param, char *map);
int			checkfilenamecub(char *map);
int			checkfirstelems(t_col_text col_text, int fd);

/* PARSING  */
//	Color
int			is_color(char *line, t_col_text col_text);
int			fill_color(char *line, int color, t_col_text col_text);
int			get_color(char *line,int index, int *code);
//	Texture
int			is_textures(char *line, t_col_text col_text);
int			fill_textures(char *line, char *name, t_col_text col_text);
int			get_texture(char *line, char **texture);
int			is_texture_ok(char *texture);
// Map
int	check_map();

/* UTILS */
int		skipspace(char *line, int i);

/* EXEC */



#endif