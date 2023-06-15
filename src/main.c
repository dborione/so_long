#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
   	t_game	game;

	if (argc != 2)
		return (1);
  //ft_init_game(&game);
  if (!ft_parse_map(&game, argv[1]))
    return (1);
  ft_pathfinding;
  // ft_init_mlx;
  // ft_load_assets;
  // ft_player_anim;
  // ft_keys_input;
  // mlx_loop(game.mlx_ptr);
  exit(0);
}