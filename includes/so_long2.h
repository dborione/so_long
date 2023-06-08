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
//#include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include "get_next_line.h"

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

typedef	struct s_map {
	int	map_size_x; //ok
	int	map_size_y; //ok
	int	C_count; //ok
	int	P_count;
	int	E_count;
	int	V_count;
	int	villain_pos_x; //ok
	int	villain_pos_y; //ok
	int	O_count;
	int	player_pos_x; //ok
	int	player_pos_y; //ok
	
	char player_current_pos;
	char villain_current_pos;
	char villain_current_pos_y;
	char villain_current_pos_x;
	char villain_next_pos;
	char object_type;
	int	exit_pos_x; //ok
	int	exit_pos_y; //ok
	char **map_array;
}	t_map;

typedef struct	s_game {
	int		moves;
	int		score;
	int		player_life;
	void	*mlx_ptr;
	void	*mlx_window;
	void	*player_img_ptr;
	void	*villain_img_ptr;
	char	*villain_relative_path;
	char	*player_img_addr;
	char	*player_relative_path;
	void	*exit_img_ptr;
	void	*wall_img_ptr;
	void	*backgnd_img_ptr;
	void	*collectible_img_ptr;
	int		bits_per_pixel; // = depth of image = bits needed to represent a pixel color
	int		line_length; // nbr of bytes used to store one line of the image in memory
	int		endian; // endian == 0: pixel color needs to be stored in little / 1: big
	t_map map;
}	t_game;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr_fd(int nbr, int fd);
int		ft_map_rectangle(char *file);
int	ft_check_map(t_game *game, char *argv);
//t_map ft_check_map(char *file);
//t_map	ft_game(char *argv1);
int	key_input(int key, t_game *game);
void	ft_load_images(t_game *game);
t_game	*ft_init_map(t_game *game);
int	ft_player_animation(t_game *game);
//int	ft_villain_patrol(t_game *game);
char	*ft_itoa(int nbr);
int	ft_player_movement(t_game *game, int player_current_pos_x, int player_current_pos_y);
int	ft_villain_movement(t_game *game, int villain_current_pos_x, int villain_current_pos_y);
int ft_death_or_success(t_game *game);
void	ft_init_game(t_game *game);
int ft_get_lines_number(int y, char *file);
int ft_build_map_array(t_game *game);
int	ft_free_array(t_map *map);
int	ft_check_lines(int fd, t_map *map, char *line);
int	ft_check_last_line(t_map *map, char *line);
int ft_check_first_line(char *line);
int	ft_check_letters(t_map  *map, char *line, int i, int y);
int ft_find_path(t_game *game);

char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	**ft_free_tab_sl(char **tab);

#endif
