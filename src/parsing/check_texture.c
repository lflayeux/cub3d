#include "cub3d.h"

bool	is_textures(char *line, t_col_text *col_text)
{
	//istextures doit s'assurer que la texture commence par NO, SO, EA, WE
	// pour pouvoir remplir les textures
	int i = 0;
	int y = 0;
	char	name[3];

	i = skipspace(line, i);
	while (line[i] && line[i] != ' ' && line[i] != '\t' && y < 2)
	{
		name[y] = line[i];
		y++;
		i++;
	}
	name[y] = '\0';
	if (y == 2)
	{
		if (fill_textures(line, name, col_text) == ERROR)
			return(printf("error textures (3) "),ERROR);
		return (TRUE);
	}
	else 
		return (FALSE);
	return (TRUE);
}

int	fill_textures(char *line, char *name, t_col_text *col_text)
{
	int i;
	int er;

	er = 0;
	i = 0;
	while (line[i] && (line[i]==' ' || line[i]=='\t'))
		i++;
	// i = skipspace(line, i);
	if (strcmp(name, "NO")== 0)
		er = get_texture(line, &(col_text->NOtext));
	else if (strcmp(name, "SO")== 0)
		er = get_texture(line, &(col_text->SOtext));
	else if (strcmp(name, "EA")== 0)
		er = get_texture(line, &(col_text->EAtext));
	else if (strcmp(name, "WE")== 0)
		er = get_texture(line, &(col_text->WEtext));
	else
		return (printf("error: unknown texture identifier (2) "), ERROR);
	return (er);
}

int	get_texture(char *line, char **texture)
{
	int i;
	int start;
	int len;
	int y;

	start = 0;
	y = 0;
	i = 0;
	i = skipspace(line, i);
	while(line[i] && (line[i] != ' ' && line[i] != '\t'))
		i++;
	i = skipspace(line, i);
	start = i;
	while(line[i] && line[i] != '\n' && line[i] != '\r')
		i++;
	len = i - start;
	*texture = malloc(len + 1);
	if (!(*texture))
		return (ERROR);
	while(y < len)
	{
		(*texture)[y] = line[start+y];
		y++;
	}
	(*texture)[y] = '\0';
	if (!is_texture_ok(*texture))
		return (ERROR);
	return (SUCCESS);
}

bool	is_texture_ok(char *texture)
{
	int fd;
	int len;

	if (!texture)
		return (FALSE);
	len = strlen(texture);
	if (len < 4)
		return (FALSE);
	if (strcmp(texture + len - 4, ".xpm") != 0)
		return (FALSE);
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	// je check si le document est remplie? je m'assure qu'il fonctionne?
    // check d'une partie specifique du fichier
	close(fd);
	return (TRUE);
}