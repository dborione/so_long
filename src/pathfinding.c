#include "../includes/so_long.h"

int ft_pathfinding(t_game *g, char **map_copy, int x, int y)
{
    char        checked;

    checked = 'X';
    if (map_copy[x][y] == 'C')
        g->path_coll_count++;
    if (map_copy[y][x] == 'E')
        g->path_exit_count++;

    map_copy[x][y] = checked;
    if (map_copy[x][y - 1] != '1' && map_copy[x][y - 1] != checked)
        ft_pathfinding(g, map_copy, x, y - 1);
    if (map_copy[x - 1][y] != '1' && map_copy[x - 1][y] != checked)
        ft_pathfinding(g, map_copy, x - 1, y);
    if (map_copy[x][y + 1] != '1' && map_copy[x][y + 1] != checked)
        ft_pathfinding(g, map_copy, x, y + 1);
    if (map_copy[x + 1][y] != '1' && map_copy[x + 1][y] != checked)
        ft_pathfinding(g, map_copy, x + 1, y);
    return (1);
}

int ft_find_path(t_game *g)
{
    int     i;
    char    **map_copy;
    
    i = -1;
    map_copy = NULL;
    map_copy = malloc((sizeof(char *) * (g->map_size_y + 1)));
    if (!map_copy)
        return (0); //and free map_array
    while(g->map_array[++i])
    {
        map_copy[i] = ft_strdup(g->map_array[i]);
        if (!map_copy[i])
            return (0); // and free
    }
    ft_get_player_pos(g);
    g->path_coll_count = 0;
    g->path_exit_count = 0;
    ft_pathfinding(g, map_copy, g->player.pos_x, g->player.pos_y);
    if (g->path_coll_count != g->coll_count 
        || g->path_exit_count!= 1)
        return (0);
    ft_free_tab(map_copy);
    return (1);
}