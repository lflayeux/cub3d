/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frene <frene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:17:08 by pandemonium       #+#    #+#             */
/*   Updated: 2025/10/29 16:10:04 by frene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "struct.h"

// =============================
// ============ INIT ===========
// =============================

int		init_mlx(t_game *game);
void	setup_hooks(t_game *game);

// =============================
// ============ FREE ===========
// =============================

void	destroy_mlx(t_game *game);
void	free_game(t_game *game);

// =============================
// ============ MOVE ===========
// =============================

void	rotate_player(t_player *player, float angle);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif