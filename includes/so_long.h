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

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "../libft/includes/libft.h"

// General
# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define MLX_FAILURE 6
# define MLX_SUCCESS 0
# define TILE_SIZE 64
# define FRAME_SPEED 30
# define FIRST_LINE 0
# define LAST_LINE 1

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

typedef struct s_parsing {
	int		fd;
	int		player_count;
	int		exit_count;
	int		coll_count;
	char	*line;
	size_t	line_len;
}	t_parsing;

typedef struct s_textures {
	char	*wall_relative_path;
	void	*wall_img_ptr;
	char	*exit_relative_path;
	void	*exit_img_ptr;
	char	*coll_relative_path;
	void	*coll_img_ptr;
}	t_textures;

typedef struct s_player {
	int		pos_x;
	int		pos_y;
	int		player_life;
	char	*relative_path;
	void	*img_ptr;
}	t_player;

typedef struct s_game {
	t_player	player;
	t_textures	t;
	void		*mlx_ptr;
	void		*mlx_window;
	int			coll_count;
	int			path_coll_count;
	int			path_exit_count;
	int			moves;
	int			map_size_x;
	int			map_size_y;
	char		**map_array;
}	t_game;

// init
void	ft_init_game(t_game *game);

// Parsing
void	ft_check_map(t_game	*g, char *arg);
int		ft_parse_map(t_game *game, char *file);
int		ft_count_lines(t_parsing *p, char *file);
void	ft_init_parsing(t_parsing *p);
int		ft_open_fd(t_parsing *p, char *file);
int		ft_free_gnl(t_parsing *p);
int		ft_build_map_array(t_parsing *p, t_game *g, char *file);

// Pathfinding
int		ft_find_path(t_game *g);

// MLX
int		ft_init_mlx(t_game *g);
void	ft_load_assets(t_game *g);
int		ft_key_input(int key, t_game *game);
void	ft_move(t_game *g);
void	ft_init_game(t_game	*g);
void	ft_init_map(t_game *g);
void	ft_init_struct(t_game *g);
void	ft_draw_moves(t_game *g);
char	**ft_free_tab(char **tab);
int		ft_red_cross(t_game *g);
void	ft_put_img(t_game *g, void *ptr, int pos1, int pos2);
void	ft_error_and_quit(int err_code);
void	ft_check_ber(char *file);
void	ft_mlx_quit(t_game *g, int exit_code);

#endif