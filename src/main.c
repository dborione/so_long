#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
  	t_game	g;

	if (argc != 2)
		return (1);
	//ft_init_struct(g);
	ft_check_map(&g, argv[1]);
	//ft_init_game(&g);
	//printf("%d\n", g.player.pos_x);
	//ft_putchar_fd(g.map_array[g.player.pos_y][g.player.pos_x], 1);
	//ft_move(&g);
  	exit(0);
}