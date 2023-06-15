#include "../includes/so_long.h"

int ft_pathfinding(char **map_copy, int y, int x)
{
    static int  c_count;
    static int  e_count;
    char        checked;

    c_count = 0;
    e_count = 0;
    checked = 'X';
    if (map_copy[y][x] == 'C')
        c_count++;
    if (map_copy[y][x] == 'E')
        e_count++;

    map_copy[y][x] = checked;
    if (map_copy[y][x - 1] != '1' && map_copy[y][x - 1] != checked)
        ft_pathfinding(map_copy, y, x - 1);
    if (map_copy[y - 1][x] != '1' && map_copy[y - 1][x] != checked)
        ft_pathfinding(map_copy, y - 1, x);
    if (map_copy[y][x + 1] != '1' && map_copy[y][x + 1] != checked)
        ft_pathfinding(map_copy, y, x + 1);
    if (map_copy[y + 1][x] != '1' && map_copy[y + 1][x] != checked)
        ft_pathfinding(map_copy, y + 1, x);
    return (1);
}

int ft_find_path(t_game *g)
{
    int i;
    char    **map_copy;
    
    i = -1;
    map_copy = malloc((sizeof(char *) * g->map_size_y + 1));
    if (!map_copy)
        return (0); //and free map_array
    while(g->map_array[++i])
    {
        map_copy[i] = ft_strdup(g->map_array[i]);
        if (!map_copy[i])
            return (0);
    }
    ft_get_positions(g);
    ft_pathfinding(map_copy, g->player.pos_y, g->player.pos_x);
    //ft_free_tab_sl(map_copy); segfault
    return (1);
}