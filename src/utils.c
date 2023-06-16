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
//     mlx_string_put(g->mlx_ptr, g->mlx_window, 0, 0, 0xFFFFFF, "moves:");
//     mlx_string_put(g->mlx_ptr, g->mlx_window, TILE_SIZE, 0, 0xFFFFFF, ft_itoa(g->moves));
// }

// void    ft_mlx_put_image_to_window(t_game *g, void *img_ptr, int pos_y,  int pos_x)
// {
//     mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, img_ptr, pos_y, pos_x);
// }