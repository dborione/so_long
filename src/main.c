#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
  	t_game	g;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong Number of Arguments", 2);
		return (1);
	}
	ft_init_struct(&g);
	ft_check_map(&g, argv[1]);
	ft_init_game(&g);
	mlx_hook(g.mlx_window, 17, 0, ft_red_cross, &g);
	mlx_loop_hook(g.mlx_ptr, ft_player_anim, &g);
	ft_move(&g);
	mlx_loop(g.mlx_ptr);
	//ft_free_tab(g.map_array);
  	exit(0);
}