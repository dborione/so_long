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

void	ft_error_and_quit(int err_code)
{
	ft_putstr_fd("Error\n", 2);
	if (err_code == 1)
		ft_putstr_fd("Wrong Number of Arguments", 2);
	if (err_code == 2)
		ft_putstr_fd("Wrong file extension", 2);	
	if (err_code == 3)
		ft_putstr_fd("File not found", 2);
	if (err_code == 4)
		ft_putstr_fd("Invalid map", 2);
	if (err_code == 5)
		ft_putstr_fd("Path not found", 2);
	exit(err_code);
}

void	ft_init_parsing(t_parsing *p)
{
	p->coll_count = 0;
	p->exit_count = 0;
	p->line_len = 0;
	p->player_count = 0;
}

void	ft_init_struct(t_game *g)
{
	g->coll_count = 0;
	g->path_coll_count = 0;
	g->path_exit_count = 0;
	g->moves = 0;
	g->map_size_x = 0;
	g->map_size_y = 0;
}

void	ft_put_img(t_game *g, void *ptr, int pos1, int pos2)
{
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window,
		ptr, pos1, pos2);
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
