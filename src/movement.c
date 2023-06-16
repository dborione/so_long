#include "../includes/so_long.h"

// //(horizontal, vertical) -> (x, y)

// /*
// ** Check if the move is valid by checking the value of the specified position
// // */
// int	ft_move_conditions(t_game *g, int player_next_pos_x, int player_next_pos_y)
// {
//     char    player_next_pos;

//     g->player.pos_x = player_next_pos_x;
//     g->player.pos_y = player_next_pos_y;
//     player_next_pos = g->map.map_array[player_next_pos_x / TILE_SIZE][player_next_pos_y / TILE_SIZE];
// 	if (player_next_pos == '1')
// 		return (0);
// 	if (player_next_pos == 'C')
// 	{
// 		g->map.map_array[player_next_pos_x / TILE_SIZE][player_next_pos_y / TILE_SIZE] = '0';
// 		//g->map.C_count--;
// 		g->score++;
// 		mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->backgnd_img_ptr, player_next_pos_x, player_next_pos_y);
// 	}
// 	// if (game->map.player_current_pos == 'E' && game->map.C_count == 0)
// 	// 	return (3);
// 	return (1);
// }


// int	ft_death_or_success(t_game *game)
// {
// 	//void	*img_ptr;
// 	mlx_clear_window(game->mlx_ptr, game->mlx_window);
// 	//mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->exit_img_ptr, game->map.exit_pos_x * TILE_SIZE, (game->map.exit_pos_y - 1) * TILE_SIZE);

// 	//img_ptr = mlx_new_image(game->mlx_ptr, (game->map.map_size_x * TILE_SIZE), (game->map.map_size_y * TILE_SIZE));
	
// 	//mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, img_ptr, 0, 0);
// 	mlx_string_put(game->mlx_ptr, game->mlx_window, 0, 0, 2, "sucess!");
// 	return (0);
// }

// // /*
// // ** Load the player images according to key touches
// // */
// int	ft_player_movement(t_game *g, int player_next_pos_x, int player_next_pos_y)
// {
// 	int	move_conditions;
	
// 	move_conditions = ft_move_conditions(g, player_next_pos_x, player_next_pos_y);
// 	if (move_conditions == 0)
// 		return (0);
// 	g->player.pos_x = player_current_pos_x;
// 	g->player.pos_y = player_current_pos_y;
// 	// if (move_conditions == 2)
// 	// {
// 	// 	//ft_success(game);
// 	// 	//mlx_clear_window(game->mlx_ptr, game->mlx_window);
// 	// 	//mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->wall_img_ptr, TILE_SIZE, TILE_SIZE);
// 	// 	//mlx_string_put(game->mlx_ptr, game->mlx_window, 0, 0, 1, "success!");
// 	// 	mlx_destroy_window(game->mlx_ptr, game->mlx_window);
// 	// 	//mlx_hook(game->mlx_window, 2, 1L<<0, ft_success, &game);
// 	// 	return (0);
// 	// }
// 	// if (move_conditions == 3)
// 	// {
// 	mlx_loop_hook(g->mlx_ptr, ft_death_or_success, &g);
// 	//}
// 	//return (1);
// 	//game->moves++;
// 	return (1);
// }


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


/*
** Get and Print key number and execute command in function
*/
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
  	if (!mlx_hook(g->mlx_window, 2, 1L<<0, ft_key_input, g))
	{
		free(g->mlx_ptr);
		exit(1);
	}
	mlx_hook(g->mlx_window, 17, 0, ft_red_cross, g);
	mlx_loop(g->mlx_ptr);
}