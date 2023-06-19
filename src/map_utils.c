#include "../includes/so_long.h"


int ft_free_and_return(t_parsing *p)
{
    free(p->line);
    return (0); 
}

void    ft_open_fd(t_parsing *p, char *file)
{
    p->fd = open(file, O_RDONLY);
    if (!p->fd)
    {
        printf("fdsfdsfd");
        exit (3);
    }
}

void    ft_init_parsing(t_parsing *p)
{
    p->coll_count = 0;
    p->exit_count = 0;
    p->line_len = 0;
    p->player_count = 0;
}

int    ft_count_lines(t_parsing *p, char *file)
{
    int i;

    i = 0;
    ft_open_fd(p, file);
    p->line = get_next_line(p->fd);
    if (!p->line)
        return (0);
    while (*p->line == '\n')
    {
        free(p->line);
        p->line = get_next_line(p->fd);
        if (!p->line)
            return (0);
    }
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

    i = 0;
    g->map_array = malloc((sizeof(char *) * (g->map_size_y + 1)));
    if (!g->map_array)
        return (0);
    ft_open_fd(p, file);
    p->line = get_next_line(p->fd);
    if (!p->line)
        return (0);
    while (*p->line == '\n')
    {
        free(p->line);
        p->line = get_next_line(p->fd);
        if (!p->line)
            return (0);
    }
    g->map_array[i] = p->line;
    while(i < g->map_size_y)
        g->map_array[++i] = get_next_line(p->fd);
    g->map_array[i] = NULL;
    close(p->fd);
    return (1);
}