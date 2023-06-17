#include "../includes/so_long.h"

int	ft_check_move(t_game *g, int pos_x, int pos_y)
{
	ft_putchar_fd(g->map_array[pos_x][pos_y], 1);
	if (g->map_array[pos_x][pos_y] == '1')
		return (0);
	if (g->map_array[pos_x][pos_y] == 'C')
	{
		g->coll_count--;
		g->map_array[pos_x][pos_y] = '0';
	}
	if (g->map_array[pos_x][pos_y] == 'E'
		&& g->coll_count == 0)
			exit(0);
	g->player.pos_x = pos_x;
	g->player.pos_y = pos_y;
	g->moves++;
	ft_init_map(g);
	//mlx_do_sync(g->mlx_ptr);
	return (1);
}

int ft_key_input(int key, t_game *g)
{
	if (key == W_KEY || key == UP_ARROW_KEY)
        return (ft_check_move(g, g->player.pos_x - 1, g->player.pos_y));
	if (key == S_KEY || key == DOWN_ARROW_KEY)
		return (ft_check_move(g, g->player.pos_x + 1, g->player.pos_y));
	if (key == D_KEY || key == RIGHT_ARROW_KEY)
		return (ft_check_move(g, g->player.pos_x, g->player.pos_y + 1));
	if (key == A_KEY || key == LEFT_ARROW_KEY)
		return (ft_check_move(g, g->player.pos_x, g->player.pos_y - 1));
	if (key == ESC_KEY)
	{
		mlx_destroy_window(g->mlx_ptr, g->mlx_window);
		exit(0);
	}
	//return (ft_player_movement(g, g->player.pos_x, g->player.pos_y));
    return (1);
}

int	ft_red_cross(t_game *g)
{
	mlx_destroy_window(g->mlx_ptr, g->mlx_window);
	exit(0);
}	

void	ft_move(t_game *g)
{
	mlx_hook(g->mlx_window, 2, 1L<<0, ft_key_input, g);
  	// if (!mlx_hook(g->mlx_window, 2, 1L<<0, ft_key_input, g))
	// {
	// 	free(g->mlx_ptr);
	// 	exit(1);
	// }

}