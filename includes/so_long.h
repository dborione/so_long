/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:40:15 by dborione          #+#    #+#             */
/*   Updated: 2023/01/05 12:40:18 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

// General
# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define MLX_FAILURE 1
# define MLX_SUCCESS 0
# define TILE_SIZE 64
# define FALSE 0
# define TRUE !(FALSE)
# define FRAME_SPEED 30

// Keys
# define ESC_KEY 53
# define A_KEY 0
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define UP_ARROW_KEY 126
# define DOWN_ARROW_KEY 125
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124

// Villain Positions
# define V_UP game->map.villain_pos_y - TILE_SIZE
# define V_DOWN game->map.villain_pos_y + TILE_SIZE
# define V_LEFT game->map.villain_pos_x - TILE_SIZE
# define V_RIGHT game->map.villain_pos_x + TILE_SIZE
# define V_X game->map.villain_pos_x
# define V_Y game->map.villain_pos_y

typedef struct s_parsing {
	char	*line;
	int	player_count;
	int	exit_count;
	int	coll_count;
	int	villain_count;
	int	fd;
	size_t line_len;
}  t_parsing;

typedef	struct s_map {
	int	map_size_x;
	int	map_size_y;
    char **map_array;
} t_map;

typedef struct	s_game {
	void	*mlx_ptr;
	void	*mlx_window;
	int		moves;
	int		score;
	int		player_life;
} t_game;

void	ft_init_game(t_game *game);
int		ft_parse_map(t_game *game, char *file);

#endif