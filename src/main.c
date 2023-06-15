#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
  	t_game	g;

	if (argc != 2)
		return (1);
	//ft_init_struct(g);
	ft_check_map(&g, argv[1]);
	ft_init_game(&g);
	ft_move(&g);
 	mlx_loop(g.mlx_ptr);
  	exit(0);
}