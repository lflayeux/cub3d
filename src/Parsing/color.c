int skipspace(char *line, int i)
{
	while(line[i] && line[i] == " ")
		i++;
	return(i);
}

int	iscolor(char *line, struct png)
{
	int i;

	i = 0;
	i = skipspace(line, i);
	if ( line[i] == "F" || line[i] == "C")
	{
		if (line[i] == "F")
		{
			if (png->Ftext != 0)
				return (printf("Error double parameter for Fcolor"),1);
			fillcolor(line, png->Fcolor, png);
			return (0);
		}
		if (line[i] == "C")
		{
			if (png->Ctext != 0)
				return(printf("Error double parameter for Ccolor"), 1);
			fillcolor(line, png->Ccolor, png);
			return (0);
		}
	}
	// else if( line[i] != "F" || line[i] != "C" || line[i] != " ")
	//     return (printf("Error wrong parameter for color"),1);
	return (1);
}

int fillcolor(char *line, int pngcolor, struct png)
{
    int i;
    int j;
    int temp_colors[3];

    j = 0;
    i = 0;
    pngcolor = 1;
    while(line[i] && (line[i] == " " || line[i] == "C" || line[i] == "F"))
        i++;
    while(j<3)
    {
        i = getcolor(line, i, &temp_colors[j]);
        if (i ==-1)
            return(printf("error:invalid RGB value"),1);
        j++;
    }
    if (pngcolor == png->Fcolor)
    {
        png->FR = temp_colors[0];
        png->FG = temp_colors[1];
        png->FB = temp_colors[2];
    }
    else
    {
        png->CR = temp_colors[0];
        png->CG = temp_colors[1];
        png->CB = temp_colors[2];
    }
    return(0);
}

int getcolor(char *line,int index, int *code)
{
    char colorcode[4];
    int i;

    i = 0;
    ft_memset(colorcode, 0, 4);
    while (line[index] && line[index] != "," && line[index] != "\n")
    {
        if (line[index]>= '0' && line[index <= '9'])
        {
            if (i<3)
                colorcode[i] = line[index];
        }
        else if(line[index] != ' ')
            return (-1);
        index++;
    }
    code = atoi((const char )colorcode);
    if (code < 0 || code > 255)
        return (printf("error : wrong number in the RGB"), -1);
    if (line[index] == ',')
        index++;
    return (index);
}
