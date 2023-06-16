#include "../includes/so_long.h"

void  ft_init_struct(t_game *g)
{
	g->coll_count = 0;
	g->path_coll_count = 0;
	g->path_exit_count = 0;
	g->moves = 0;
	g->map_size_x = 0;
	g->map_size_y = 0;
}
