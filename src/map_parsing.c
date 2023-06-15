#include "../includes/so_long.h"

void    ft_gnl(char *line, int fd)
{
    line = get_next_line(fd);
    free(line);
}

int  ft_check_valid_map(t_parsing *p)
{
    if (p->player_count != 1)
        return (0);
    if (p->exit_count != 1)
        return (0);
    if (p->coll_count < 1)
        return (0);
    if (p->villain_count < 1)
        return (0);
    return (1);
}

int ft_middle_lines(t_parsing *p)
{
    p->line = get_next_line(p->fd);
    if (ft_strlen(p->line) != p->line_len
        && ft_strlen(p->line) != 0)
    {
        free(p->line);
        return (0);
    }
    // if (*p->line != '1'
    //     || p->line[p->line_len - 1] != '1')
    //     return (0);
    // p->line++;
    // while(*p->line)
    // {
    //     if (*p->line == 'P')
    //         p->player_count++;
    //     if (*p->line == 'C')
    //         p->coll_count++;
    //     if (*p->line == 'V')
    //         p->villain_count++;
    //     if (*p->line == 'E')
    //         p->exit_count++;
    //     p->line++;
    // }
    //free(p->line);
    return (1);
}

int ft_first_and_last(t_parsing *p, int x)
{
    int i;
    size_t last_line_len;

    i = 0;
    p->line = get_next_line(p->fd);
    i = ft_check_walls(p, i);
    if (x == FIRST_LINE && p->line[i] != '\n')
        return (ft_free_and_return(p));
    if (x == LAST_LINE && p->line[i] != '\0')
        return (ft_free_and_return(p));
    if (x == LAST_LINE)
    {
        last_line_len = ft_strlen(p->line);
        if (last_line_len != p->line_len - 1)
            return (ft_free_and_return(p));
    }
    p->line_len = ft_strlen(p->line);
    return (1);
}

int ft_parse_map(t_game *game, char *file)
{
    t_parsing   p;
    int         i;

    ft_init_parsing(&p);
    i = ft_count_lines(&p, file);
    if (i < 3)
        return (0);
    game->map.map_size_y = i;
    ft_open_fd(&p, file);
    if (!ft_first_and_last(&p, FIRST_LINE))
        return (0);
    while (i > 2)
    {
        free(p.line);
        p.line = get_next_line(p.fd);
        //printf("%s\n", p.line);  
        // if (!ft_middle_lines(&p))
        //     return (0);
        i--;
    }
    if (!ft_first_and_last(&p, LAST_LINE))
        return (0);
   // ft_check_valid_map(game);
    return (1);
}
