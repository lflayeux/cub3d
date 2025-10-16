/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:29:06 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/16 16:40:58 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_map map;
	(void)argc;
	if (check_map(argv[1], &map))
		printf(ONRED "ERROR DE MAP" RESET);
	ft_free_tab((void **)map.map);
	return 0;
}