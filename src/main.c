#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
   	t_game	game;

	if (argc != 2)
		return (ft_error(1));
    ft_init_game;
    ft_map_parsing;
    ft_pathfinding;
    ft_init_mlx;
    ft_load_assets;
    ft_player_anim;
    ft_keys_input;
    mlx_loop(game.mlx_ptr);
    exit(0);
}