#include "cub3d.h"

int skipspace(char *line, int i)
{
	while(line[i] && line[i] == ' ')
		i++;
	return(i);
}

int	is_color(char *line, t_col_text col_text)
{
	int i;

	i = 0;
	i = skipspace(line, i);
	if ( line[i] == 'F' || line[i] == 'C')
	{
		if (line[i] == 'F')
		{
			if (col_text.Fcolor != 0)
				return (printf("Error double parameter for Fcolor"),1);
			fill_color(line, col_text.Fcolor, col_text);
			return (0);
		}
		if (line[i] == 'C')
		{
			if (col_text.Ccolor != 0)
				return(printf("Error double parameter for Ccolor"), 1);
			fill_color(line, col_text.Ccolor, col_text);
			return (0);
		}
	}
	// else if( line[i] != "F" || line[i] != "C" || line[i] != " ")
	//     return (printf("Error wrong parameter for color"),1);
	return (1);
}

int fill_color(char *line, int color, t_col_text col_text)
{
    int i;
    int j;
    int temp_colors[3];

    j = 0;
    i = 0;
    color = 1;
    while(line[i] && (line[i] == ' ' || line[i] == 'C' || line[i] == 'F'))
        i++;
    while(j<3)
    {
        i = get_color(line, i, &temp_colors[j]);
        if (i ==-1)
            return(printf("error:invalid RGB value"),1);
        j++;
    }
    if (color == col_text.Fcolor)
    {
        col_text.FR = temp_colors[0];
        col_text.FG = temp_colors[1];
        col_text.FB = temp_colors[2];
    }
    else
    {
        col_text.CR = temp_colors[0];
        col_text.CG = temp_colors[1];
        col_text.CB = temp_colors[2];
    }
    return(0);
}

int get_color(char *line,int index, int *code)
{
    char colorcode[4];
    int i;

    i = 0;
    ft_memset(colorcode, 0, 4);
    while (line[index] && line[index] != ',' && line[index] != '\n')
    {
        if (line[index]>= '0' && line[index] <= '9')
        {
            if (i<3)
                colorcode[i] = line[index];
        }
        else if(line[index] != ' ')
            return (-1);
        index++;
    }
    *code = atoi(colorcode);
    if (*code < 0 || *code > 255)
        return (printf("error : wrong number in the RGB"), -1);
    if (line[index] == ',')
        index++;
    return (index);
}
