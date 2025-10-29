#include "cub3d.h"

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
	//check si le fichier n'est pas corrompue avec minlx image
	// je check si le document est remplie? je m'assure qu'il fonctionne?
	// check d'une partie specifique du fichier
	close(fd);
	return (TRUE);
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
		(*texture)[y] = line[start + y];
		y++;
	}
	(*texture)[y] = '\0';
	if (is_texture_ok(*texture) == FALSE)
		return (ERROR);
	return (SUCCESS);
}


bool	check_texture_name(char *line)
{
	int	i;
	int	y;
	
	i = 0;
	y = 0;
		while (line[i] && (line[i]==' ' || line[i]=='\t'))
		i++;
	while(line[i+y] && (line[i+y] != ' ' && line[i+y]!= '\t'))
		y++;
	if (y > 2)
		return (FALSE);
	return (TRUE);
}


int	fill_textures(char *line, char *name, t_col_text *col_text)
{
	int result;
	
	result = 0;
	if (!check_texture_name(line))
		return (ERROR);
	if (strcmp(name, "NO")== 0 && col_text->no_fill != TRUE )
	{
		result = get_texture(line, &(col_text->no_text));
		col_text->no_fill = TRUE;
	}
	else if (strcmp(name, "SO")== 0 && col_text->so_fill != TRUE)
	{
		result = get_texture(line, &(col_text->so_text));
		col_text->so_fill = TRUE;
	}
	else if (strcmp(name, "EA")== 0 && col_text->ea_fill != TRUE)
	{
		result = get_texture(line, &(col_text->ea_text));
		col_text->ea_fill = TRUE;
	}
	else if (strcmp(name, "WE")== 0 && col_text->we_fill != TRUE)
	{
		result = get_texture(line, &(col_text->we_text));
		col_text->we_fill = TRUE;
	}
	else
		return (ERROR);
	return (result);
}


bool	is_texture(char *line, t_col_text *col_text)
{
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
			return(FALSE);
		return (TRUE);
	}
	else 
		return (FALSE);
	return (TRUE);
}