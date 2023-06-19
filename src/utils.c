#include "../includes/so_long.h"

void    ft_init_struct(t_game *g)
{
	g->coll_count = 0;
	g->path_coll_count = 0;
	g->path_exit_count = 0;
	g->moves = 0;
	g->map_size_x = 0;
	g->map_size_y = 0;
}

// void    ft_draw_moves(t_game *g)
// {
//     mlx_string_put(g->mlx_ptr, g->mlx_window, 0, TILE_SIZE, 0xFFFFFF, "moves:");
//     mlx_string_put(g->mlx_ptr, g->mlx_window, TILE_SIZE, TILE_SIZE, 0xFFFFFF, ft_itoa(g->moves));
// }

// void    ft_mlx_put_image_to_window(t_game *g, void *img_ptr, int pos_y,  int pos_x)
// {
//     mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, img_ptr, pos_y, pos_x);
// }

// void ft_coins(t_game *g, char *path)
// {
// 	int		img_width = TILE_SIZE;
// 	int		img_height = TILE_SIZE;
// 	// int	i;
// 	// int j;

// 	// i = 0;
// 	// j = 0;
// 	mlx_destroy_image(g->mlx_ptr, g->t.coll_img_ptr);
// 	g->t.coll_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, path, &img_width, &img_height);
// 	// while(j < g->map_size_y)
// 	// {
// 	// 	while(i <= g->map_size_x)
// 	// 	{
// 			//if (g->map_array[j][i] == 'C')
// 				mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->t.coll_img_ptr,
// 					i * TILE_SIZE, j * TILE_SIZE);
// 	// 		i++;
// 	// 	}
// 	// 	j++;
// 	// 	i = 0;
// 	// }
// }


// int	ft_animation(t_game *g)
// {
// 	static int		frame;
// 	int		img_width = TILE_SIZE;
// 	int		img_height = TILE_SIZE;
// 	if (frame == FRAME_SPEED)
// 	{
// 		g->t.coll_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, "./assets/textures/coll/coin_3.xpm", &img_width, &img_height);
// 		//ft_coins(g, "./assets/textures/coll/coin_3.xpm");
// 		frame = 0;
// 	}
// 	if (frame < (FRAME_SPEED / 2))
// 		g->t.coll_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, "./assets/textures/coll/coin_3.xpm", &img_width, &img_height);
// 		//ft_coins(g, "./assets/textures/coll/coin_1.xpm");
// 	else
// 		g->t.coll_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, "./assets/textures/coll/coin_3.xpm", &img_width, &img_height);
// 		//ft_coins(g, "./assets/textures/coll/coin_2.xpm");
// 	frame++;
// 	return (1);
// }

// int	ft_player_anim(t_game *g)
// {
// 	static int		frame;
// 	int		img_width = TILE_SIZE;
// 	int		img_height = TILE_SIZE;

// 	ft_init_map(g);
// 	if (frame == FRAME_SPEED)
// 		frame = 0;
// 	if (frame < 10)
// 		g->player.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, "./assets/textures/coll/coin_2.xpm", &img_width, &img_height);
// 	else if (frame >= 10 && frame < 20)
// 		g->player.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, "./assets/textures/coll/coin_1.xpm", &img_width, &img_height);
// 	else
// 		g->player.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, "./assets/textures/coll/coin_2.xpm", &img_width, &img_height);
// 	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->player.img_ptr, g->player.pos_y * TILE_SIZE, g->player.pos_x * TILE_SIZE);
// 	frame++;
// 	return (1);
// }