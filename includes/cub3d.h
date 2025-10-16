/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:37:49 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/16 15:13:46 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H	

# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "./colors.hpp"

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


int	check_map();

#endif