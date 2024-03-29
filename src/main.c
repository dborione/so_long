/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:51:28 by dborione          #+#    #+#             */
/*   Updated: 2023/06/21 15:52:33 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_red_cross(t_game *g)
{
	ft_mlx_quit(g, MLX_SUCCESS);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		ft_error_and_quit(1);
	ft_init_struct(&g);
	ft_check_map(&g, argv[1]);
	ft_init_game(&g);
	mlx_hook(g.mlx_window, 17, 0, ft_red_cross, &g);
	ft_move(&g);
	mlx_loop(g.mlx_ptr);
	ft_mlx_quit(&g, MLX_SUCCESS);
}
