/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:52:37 by dborione          #+#    #+#             */
/*   Updated: 2023/06/21 15:59:29 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_img(t_game *g, void *ptr, int pos1, int pos2)
{
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window,
		ptr, pos1, pos2);
}

int	ft_init_mlx(t_game *g)
{
	g->mlx_ptr = mlx_init();
	if (!g->mlx_ptr)
		ft_mlx_quit(g, MLX_FAILURE);
	g->mlx_window = mlx_new_window(g->mlx_ptr,
			((g->map_size_x - 1) * TILE_SIZE), ((g->map_size_y + 1)
				* TILE_SIZE), "so_long");
	if (!g->mlx_window)
	{
		free(g->mlx_ptr);
		ft_mlx_quit(g, MLX_FAILURE);
	}
	return (1);
}

void	ft_init_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	mlx_clear_window(g->mlx_ptr, g->mlx_window);
	while (++j < g->map_size_y)
	{
		while (++i <= g->map_size_x)
		{
			if (g->map_array[j][i] == '1')
				ft_put_img(g, g->t.wall_img_ptr, i * TILE_SIZE, j * TILE_SIZE);
			if (g->map_array[j][i] == 'C')
				ft_put_img(g, g->t.coll_img_ptr, i * TILE_SIZE, j * TILE_SIZE);
			if (g->map_array[j][i] == 'E')
				ft_put_img(g, g->t.exit_img_ptr, i * TILE_SIZE, j * TILE_SIZE);
		}
		i = -1;
	}
	ft_put_img(g, g->player.img_ptr, g->player.pos_y * TILE_SIZE,
		g->player.pos_x * TILE_SIZE);
	ft_draw_moves(g);
}

void	ft_load_assets(t_game *g)
{
	int	img_width;
	int	img_height;

	img_width = TILE_SIZE;
	img_height = TILE_SIZE;
	g->player.relative_path = "./assets/player/sprite_1.xpm";
	g->t.wall_relative_path = "./assets/walls/sprite_2.xpm";
	g->t.exit_relative_path = "./assets/exit/sprite_3.xpm";
	g->t.coll_relative_path = "./assets/collectibles/sprite_0.xpm";
	g->player.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
			g->player.relative_path, &img_width, &img_height);
	g->t.wall_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
			g->t.wall_relative_path, &img_width, &img_height);
	g->t.exit_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
			g->t.exit_relative_path, &img_width, &img_height);
	g->t.coll_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
			g->t.coll_relative_path, &img_width, &img_height);
}

void	ft_init_game(t_game	*g)
{
	ft_init_mlx(g);
	ft_load_assets(g);
	ft_init_map(g);
}
