#include "../includes/so_long.h"

int ft_check_map(t_game  *game, char *file)
{
    int         y;
    int         fd;
    char        *line = NULL;

    fd = open(file, O_RDONLY);
    if (!fd)
        exit (2);
    y = ft_get_lines_number(y, file);
    game->map.map_size_y = y;
    line = get_next_line(fd);
    game->map.map_size_x = ft_check_first_line(line);
    if (game->map.map_size_x <= 2)
    {
        free(line);
        return (0);
    }
    if (ft_build_map_array(game) == 0)
    {
        free(line);
        return (0);
    }
    game->map.map_array[0] = line;
    //free(line);
    if (!ft_check_lines(fd, &game->map, line)) //problem with return: segfault when returning check_lines directly
        return (0);
    return (1);
}
