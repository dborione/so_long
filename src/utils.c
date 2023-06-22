/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:15:17 by dborione          #+#    #+#             */
/*   Updated: 2023/06/22 10:22:25 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_struct(t_game *g)
{
	g->coll_count = 0;
	g->path_coll_count = 0;
	g->path_exit_count = 0;
	g->moves = 0;
	g->map_size_x = 0;
	g->map_size_y = 0;
}

void	ft_draw_moves(t_game *g)
{
	int	s1_pos;

	s1_pos = ((g->map_size_x / 2) - 1) * TILE_SIZE;
	mlx_string_put(g->mlx_ptr, g->mlx_window, s1_pos,
		g->map_size_y * TILE_SIZE, 0xFFFFFF, "moves:");
	mlx_string_put(g->mlx_ptr, g->mlx_window, s1_pos + TILE_SIZE,
		g->map_size_y * TILE_SIZE, 0xFFFFFF, ft_itoa(g->moves));
}
