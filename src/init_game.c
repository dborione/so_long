#include "../includes/so_long.h"

void ft_get_player_pos(t_game *g)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while (g->map_array[++i])
    {
        while(g->map_array[i][++j])
        { 
            if (g->map_array[i][j] == 'P')
            {
                g->player.pos_x = i;
                g->player.pos_y = j;
            }
        }
        j = 0;
    }
}

int ft_init_mlx(t_game *g)
{
    g->mlx_ptr = mlx_init();
	if (!g->mlx_ptr)
		return (0);
	g->mlx_window = mlx_new_window(g->mlx_ptr, (g->map_size_x * TILE_SIZE),
        (g->map_size_y * TILE_SIZE), "so_long");
	if (!g->mlx_window)
	{
		free(g->mlx_ptr);
		return (0);
	}
    return (1);
}

void ft_init_map(t_game *g)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	mlx_clear_window(g->mlx_ptr, g->mlx_window);
	while(++j < g->map_size_y)
	{
		while(++i <= g->map_size_x)
		{
			if (g->map_array[j][i] == '1')
				mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->t.wall_img_ptr,
					i * TILE_SIZE, j * TILE_SIZE);
			if (g->map_array[j][i] == 'C')
			{
				mlx_loop_hook(g->mlx_ptr, *ft_animation, g);
				mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->t.coll_img_ptr,
					i * TILE_SIZE, j * TILE_SIZE);
			}
			if (g->map_array[j][i] == 'E')
				mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->t.exit_img_ptr,
					i * TILE_SIZE, j * TILE_SIZE);
		}
		i = -1;
	}
//	mlx_loop_hook(g->mlx_ptr, *ft_animation, g);
   	ft_mlx_put_image_to_window(g, g->player.img_ptr, g->player.pos_y * TILE_SIZE,  g->player.pos_x * TILE_SIZE);
	ft_draw_moves(g);
}


int ft_load_assets(t_game *g)
{
	int		img_width = TILE_SIZE;
	int		img_height = TILE_SIZE;
    g->player.relative_path = "./assets/player/player_1.xpm";
    g->t.wall_relative_path = "./assets/player/player_1.xpm";
	g->t.exit_relative_path = "./assets/textures/walls/wall3.xpm";
	g->t.coll_relative_path = "./assets/textures/coll/coin_3.xpm";
    g->player.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, g->player.relative_path, &img_width, &img_height);
    g->t.wall_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, g->t.wall_relative_path, &img_width, &img_height);
	g->t.exit_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, g->t.exit_relative_path, &img_width, &img_height);
	g->t.coll_img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, g->t.coll_relative_path, &img_width, &img_height);
}

void	ft_init_game(t_game	*g)
{
	ft_init_mlx(g);
  	ft_load_assets(g);
	ft_init_map(g);
	
}

// void	ft_update_image(char *relative_path, void *img_ptr, t_game *g)
// {
// 	int	img_width = TILE_SIZE;
// 	int img_height = TILE_SIZE;

// 	mlx_clear_window(game->mlx_ptr, game->mlx_window);
// 	ft_init_map(game);

// 	game->player_relative_path = relative_path;
// 	img_ptr = relative_path;

// 	game->player_img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, game->player_relative_path, &img_width, &img_height);
// }

// void	ft_player_animation_bis(t_game *g)
// {
// 	static int	frame;

// 	frame++;
// 	if (frame > (FRAME_SPEED / 2) && frame <= FRAME_SPEED)
// 		ft_update_image("./assets/player/player_2.xpm", g->player.img_ptr, g);
// 	else if (frame > FRAME_SPEED && frame <= FRAME_SPEED * 2)
// 		ft_update_image("./assets/player/player_3.xpm", g->player.img_ptr, g);
// 	else if (frame > FRAME_SPEED * 2)
// 	{
// 		ft_update_image("./assets/player/player_4.xpm", g->player.img_ptr, g);;
// 		frame = 0;
// 	}
// 	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->player.img_ptr, g->player.pos_x, g->player.pos_y);
// 	//mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->villain_img_ptr, game->map.villain_pos_x,  game->map.villain_pos_y);
// }

