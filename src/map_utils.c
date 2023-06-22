/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:06:48 by dborione          #+#    #+#             */
/*   Updated: 2023/06/21 16:11:38 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_ber(char *file)
{
	int	ext;

	ext = ft_strlen(file) - 4;
	if (ft_strncmp(&file[ext], ".ber", 4))
		ft_error_and_quit(2);
}

int	ft_free_and_quit(t_parsing *p)
{
	while (p->line)
	{
		free(p->line);
		p->line = get_next_line(p->fd);
	}
	free(p->line);
	return (0);
}

int	ft_open_fd(t_parsing *p, char *file)
{
	p->fd = open(file, O_RDONLY);
	if (p->fd == -1)
		return (0);
	return (1);
}

int	ft_count_lines(t_parsing *p, char *file)
{
	int	i;

	i = 0;
	if (!ft_open_fd(p, file))
		ft_error_and_quit(3);
	ft_check_ber(file);
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

int	ft_build_map_array(t_parsing *p, t_game *g, char *file)
{
	int	i;

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
	while (i < g->map_size_y)
		g->map_array[++i] = get_next_line(p->fd);
	g->map_array[i] = NULL;
	close(p->fd);
	return (1);
}
