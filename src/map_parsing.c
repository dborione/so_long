#include "../includes/so_long.h"

int ft_free_and_quit(t_parsing *p)
{
    while(p->line)
    {
        free(p->line);
        p->line = get_next_line(p->fd);
    }
    free(p->line);
    return (0);
}

int ft_first_and_last(t_parsing *p, int x)
{
    int     i;
    size_t  last_line_len;

    i = 0;
    p->line = get_next_line(p->fd);

    while (p->line[i] == '\n')
    {
        free(p->line);
        p->line = get_next_line(p->fd);
    }
    while (p->line[i] == '1')
        i++;
    if (x == FIRST_LINE && p->line[i] != '\n')
        return (ft_free_and_quit(p));
    if (x == LAST_LINE && p->line[i] != '\0')
        return (ft_free_and_quit(p));
    if (x == LAST_LINE)
    {
        last_line_len = ft_strlen(p->line);
        if (last_line_len != p->line_len - 1)
            return (ft_free_and_quit(p));
    }
    p->line_len = ft_strlen(p->line);
    free(p->line);
    return (1);
}

int ft_middle_lines(t_parsing *p)
{
    int i;

    i = 0;
    p->line = get_next_line(p->fd);
    if (ft_strlen(p->line) != p->line_len)
        return (ft_free_and_quit(p));
    if (p->line[i] != '1'
        || p->line[p->line_len - 2] != '1')
        return (ft_free_and_quit(p));
    i++;
    while(p->line[i])
    {
        if (p->line[i] != 'P' && p->line[i] != 'E' 
            && p->line[i] != 'C' && p->line[i] != '0' 
            && p->line[i] != '1' && p->line[i] != '\n')
            return (ft_free_and_quit(p));
        if (p->line[i] == 'P')
            p->player_count++;
        if (p->line[i] == 'C')
            p->coll_count++;
        if (p->line[i] == 'E')
            p->exit_count++;
        i++;
    }
    free(p->line);
    return (1);
}

int  ft_check_valid_map(t_parsing *p)
{
    if (p->player_count != 1 || p->exit_count != 1 ||
        p->coll_count < 1)
        return (0); //leak here
    return (1);
}


int ft_parse_map(t_game *g, char *file)
{
    t_parsing   p;
    int         i;

    ft_init_parsing(&p);
    i = ft_count_lines(&p, file);
    if (i < 3)
        return (0);
    g->map_size_y = i;
    ft_open_fd(&p, file);
    if (!ft_first_and_last(&p, FIRST_LINE))
        return (0);
    while (i > 2)
    {
        if (!ft_middle_lines(&p))
            return (0);
        i--;
    }
    if (!ft_first_and_last(&p, LAST_LINE))
        return (0);
    if (!ft_check_valid_map(&p))
        return (0);
    g->map_size_x = p.line_len;
    g->coll_count = p.coll_count;
    ft_build_map_array(&p, g, file);
    if (!ft_find_path(g))
    {
        ft_free_and_quit(&p);
	    ft_putstr_fd("Path not found", 2);
        exit(1);
    }
    return (1);
}

void	ft_check_map(t_game	*g, char *arg)
{
  	if (!ft_parse_map(g, arg))
    {
	    ft_putstr_fd("Invalid map", 2);
        exit(2);
    }
}