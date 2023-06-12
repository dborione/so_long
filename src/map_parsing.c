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
    get_next_line(p->fd);
    if (ft_strlen(p->line) != p->line_len)
        return (0);
    if (*p->line != '1'
        || p->line[p->line_len - 1] != '1')
        return (0);
    p->line++;
    while(*p->line)
    {
        if (*p->line == 'P')
            p->player_count++;
        if (*p->line == 'C')
            p->coll_count++;
        if (*p->line == 'V')
            p->villain_count++;
        if (*p->line == 'E')
            p->exit_count++;
        p->line++;
    }
    free(p->line);
    return (1);
}

int ft_first_line(t_parsing *p)
{
    int i;

    i = -1;
    p->line = get_next_line(p->fd);
    while (p->line[++i])
    {
        if (p->line[i] != '1')
            break ;
    }
    if (p->line[i] != '\n')
    {
        free(p->line);
        return (0);    
    }
    free(p->line);
    return (1);
}

int ft_last_line(t_parsing *p)
{
    // if (ft_strlen(p->line) != p->line_len)
    //     return (0);
    // while (*p->line)
    // {
    //     if (*p->line != '1')
    //     {
    //         free(p->line);
    //         return (0);
    //     }
    //     p->line++;
    // }
    // free(p->line);
    return (1);
}

int ft_parse_map(t_game *game, char *file)
{
    t_parsing p;

    p.coll_count = 0;
    p.exit_count = 0;
    p.line = NULL;
    p.line_len = 0;
    p.player_count = 0;
    p.villain_count = 0;
    p.fd = open(file, O_RDONLY);
    if (!p.fd)
        exit (2);

    //printf("%s\n", p.line);
   if (!ft_first_line(&p))
       return (0);
    // while (p.fd)
    // {
    //     if (!ft_middle_lines(&p))
    //         return (0);
    // }
    // if (!ft_last_line(&p))
    //     return (0);
   // ft_check_valid_map(game);
    return (1);
}


// int ft_check_map(t_game  *game, char *file)
// {
//     int         y;
//     int         fd;
//     char        *line = NULL;

//     fd = open(file, O_RDONLY);
//     if (!fd)
//         exit (2);
//     y = ft_get_lines_number(y, file);
//     game->map.map_size_y = y;
//     line = get_next_line(fd);
//     game->map.map_size_x = ft_check_first_line(line);
//     if (game->map.map_size_x <= 2)
//     {
//         free(line);
//         return (0);
//     }
//     if (ft_build_map_array(game) == 0)
//     {
//         free(line);
//         return (0);
//     }
//     game->map.map_array[0] = line;
//     //free(line);
//     if (!ft_check_lines(fd, &game->map, line)) //problem with return: segfault when returning check_lines directly
//         return (0);
//     return (1);
// }


