#include "../includes/so_long.h"

int ft_free_and_return(t_parsing *p)
{
    free(p->line);
    return (0); 
}

int    ft_check_walls(t_parsing *p, int i)
{
    while (p->line[i] == '1')
        i++;
    return (i);
}

void    ft_open_fd(t_parsing *p, char *file)
{
    p->fd = open(file, O_RDONLY);
    if (!p->fd)
        exit (3);
}

void    ft_init_parsing(t_parsing *p)
{
    p->coll_count = 0;
    p->exit_count = 0;
    p->line_len = 0;
    p->player_count = 0;
    p->villain_count = 0;
}

int    ft_count_lines(t_parsing *p, char *file)
{
    int i;

    i = 0;
    ft_open_fd(p, file);
    p->line = get_next_line(p->fd);
    while (p->line)
    {
        free(p->line);
        p->line = get_next_line(p->fd);
        i++;
    }
    free(p->line);
    close(p->fd);
    return (i);
}

int ft_build_map_array(t_parsing *p, t_game *g, char *file)
{
    int i;
    int j;

    i = -1;
    j = g->map.map_size_y;
    g->map.map_array = malloc((sizeof(char *) * g->map.map_size_y + 1));
    if (!g->map.map_array)
        return (0);
    ft_open_fd(p, file);
    while(i < j)
        g->map.map_array[++i] = get_next_line(p->fd);
    close(p->fd);
    return (1);
}