#include "cub3d.h"



bool    is_color(char *line, t_col_text *col_text)
{
	int i;

	i = 0;
	i = skipspace(line, i);
	if ( line[i] == 'F' || line[i] == 'C')
	{
		if (line[i] == 'F')
		{
			if (col_text->Fcolor != 0)
				return (printf("Error double parameter for Fcolor"), ERROR);
			fill_color(line, 'F', col_text);
			return (TRUE);
		}
		if (line[i] == 'C')
		{
			if (col_text->Ccolor != 0)
				return(printf("Error double parameter for Ccolor"), ERROR);
			fill_color(line, 'C', col_text);
			return (TRUE);
		}
	}
	// else if( line[i] != "F" || line[i] != "C" || line[i] != " ")
	//     return (printf("Error wrong parameter for color"),1);
	return (FALSE);
}

int fill_color(char *line, char color, t_col_text *col_text)
{
	int i;
	int j;
	int temp_colors[3];

	j = 0;
	i = 0;
	if (!is_coma_ok(line))
		return(printf("error: RGB format incorrect (expected R,G,B)\n"), ERROR);
	while(line[i] && (line[i] == ' ' || line[i] == 'C' || line[i] == 'F'))
		i++;
	while(j<3)
	{
		i = get_color(line, i, &temp_colors[j]);
		if (i ==-1)
			return(printf("error:invalid RGB value\n"), ERROR);
		j++;
	}
	if (color == 'F' )
	{
		col_text->FR = temp_colors[0];
		col_text->FG = temp_colors[1];
		col_text->FB = temp_colors[2];
		col_text->Fcolor++;
	}
	else if (color == 'C')
	{
		col_text->CR = temp_colors[0];
		col_text->CG = temp_colors[1];
		col_text->CB = temp_colors[2];
		col_text->Ccolor++;
	}
	else
		return (ERROR);
	
	return(SUCCESS);
}

int get_color(char *line,int index, int *code)
{
	char colorcode[4];
	int i;
	int size;

	size = 0;
	i = 0;
	ft_memset(colorcode, 0, 4);
	while(line[index] && (line[index] == ' ' || line[index] == '\t')) 
		index++;
	if (!is_size_ok(line, index))
		return (printf("error: Usage: 0>'RGB'<255 \n"), ERROR);
	while (line[index] && line[index] != ',' && line[index] != '\n')
	{
		if (line[index]>= '0' && line[index] <= '9')
		{
			if (i<3)
			{
				colorcode[i] = line[index];
				i++;
			}
		}
		else if(line[index] != ' ')
			return (ERROR);
		index++;
	}
	*code = atoi(colorcode);
	if (*code < 0 || *code > 255)
		return (printf("error : wrong number in the RGB"), ERROR);
	if (line[index] == ',')
		index++;
	return (index);
}
