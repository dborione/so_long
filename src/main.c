#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
   	t_game	g;

	if (argc != 2)
		return (1);
  //ft_init_game(&game);
  if (!ft_parse_map(&g, argv[1]))
    return (1);
  ft_find_path(&g);
  ft_init_mlx(&g);
  ft_load_assets(&g);
  // ft_player_anim;
  // ft_keys_input;
  mlx_loop(g.mlx_ptr);
  exit(0);
}