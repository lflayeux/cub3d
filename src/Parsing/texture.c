int istextures(char *line, int textures)
{
	//istextures doit s'assurer que la texture commence par NO, SO, EA, WE
	// pour pouvoir remplir les textures
	// 
	int i = 0;
	int y = 0;
	char	name[3];

	i = skipspace(line, i);
	while (line[i] && line[i] != " " && y < 2)
	{
		name[y] = line[i];
		y++;
		i++;
	}
	name[y] = '\0';
	if (y == 2)
	{
		if (filltextures(line, name, png) == 1)
			return(printf("error textures"),1);
		return (0);
	}
	else 
		return (printf("error texture writing"),1);
	return (0);
}


int filltextures(char *line, char *name, struct png)
{
	int i;
	int er;

	er = 0;
	i = 0;
	i = skipspace(line, i);
	if (strcmp(name, "NO")== 0)
		er = get_texture(line, &(png->NOtext));
	if (strcmp(name, "SO")== 0)
		er = get_texture(line, &(png->SOtext));
	if (strcmp(name, "EA")== 0)
		er = get_texture(line, &(png->EAtext));
	if (strcmp(name, "WE")== 0)
		er = get_texture(line, &(png->WEtext));
	else
		return (printf("error: unknown texture identifier"),1);
	return (er);
}

int get_texture(char *line, char **texture)
{
	int i;
	int start;
	int len;
	int y;

	start = 0;
	y = 0;
	i = 0;
	i = skipspace(line, i);
	while(line[i] && line[i] != " ")
		i++;
	i = skipspace(line, i);
	start = i;
	while(line[i] && line[i] != "\n" && line[i] != '\r')
		i++;
	len = i - start;
	*texture = malloc(len + 1);
	if (!(*texture))
		return (-1);
	while(y < len)
	{
		(*texture)[y] = line[start+y];
		y++;
	}
	(*texture)[y] = '\0';
	if (is_texture_ok(*texture))
		return (1);
	return (0);
}

int is_texture_ok(char *texture)
{
	int fd;
	int len;

	if (!texture)
		return (0);
	len = strlen(texture);
	if (len < 4)
		return (0);
	if (strcmp(texture + len - 4, ".xpm") != 0)
		return (1);
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		return (1);
	//je check si le document est remplie? je m'assure qu'il fonctionne?
    // check d'une partie specifique du fichier
	close(fd);
	return (0);
}