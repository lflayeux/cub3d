#include "cub3d.h"

bool is_size_ok(char *line, int index)
{
	int i;

	i = 0;
	while(line[index] && line[index] != ',')
	{
		index++;
		if (line[index] != ' ' && line[index] != '\t' )
			i++;
	}
	if (i>3)
		return(FALSE);
	return (TRUE);
}

bool is_coma_ok(char *line)
{
	int i;
	int comma_count;

	i = 0;
	comma_count=0;
	while(line[i])
	{
		if (line[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
		return(FALSE);
	return (TRUE);
}

int skipspace(char *line, int i)
{
	while(line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return(i);
}