/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:15:10 by dborione          #+#    #+#             */
/*   Updated: 2023/06/22 10:21:22 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_get_player_pos(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (g->map_array[++i])
	{
		while (g->map_array[i][++j])
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

static int	ft_pathfinding(t_game *g, char **map_copy, int x, int y)
{
	char	checked;

	checked = 'X';
	if (map_copy[x][y] == 'C')
		g->path_coll_count++;
	if (map_copy[x][y] == 'E')
		g->path_exit_count++;
	map_copy[x][y] = checked;
	if (map_copy[x][y + 1] != '1' && map_copy[x][y + 1] != checked)
		ft_pathfinding(g, map_copy, x, y + 1);
	if (map_copy[x][y - 1] != '1' && map_copy[x][y - 1] != checked)
		ft_pathfinding(g, map_copy, x, y - 1);
	if (map_copy[x - 1][y] != '1' && map_copy[x - 1][y] != checked)
		ft_pathfinding(g, map_copy, x - 1, y);
	if (map_copy[x + 1][y] != '1' && map_copy[x + 1][y] != checked)
		ft_pathfinding(g, map_copy, x + 1, y);
	return (1);
}

int	ft_find_path(t_game *g)
{
	int		i;
	char	**map_copy;

	i = -1;
	map_copy = malloc(sizeof(char *) * (g->map_size_y + 1));
	if (!map_copy)
		return (0);
	while (g->map_array[++i])
		map_copy[i] = ft_strdup(g->map_array[i]);
	ft_get_player_pos(g);
	g->path_coll_count = 0;
	g->path_exit_count = 0;
	ft_pathfinding(g, map_copy, g->player.pos_x, g->player.pos_y);
	if (g->path_coll_count != g->coll_count
		|| g->path_exit_count != 1)
	{
		ft_free_tab(map_copy);
		return (0);
	}
	ft_free_tab(map_copy);
	return (1);
}
