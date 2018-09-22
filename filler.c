/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:08:24 by mntumba           #+#    #+#             */
/*   Updated: 2018/09/22 08:08:30 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_player_pos(t_map *m, t_player *pl)
{
	int		y;
	int		x;
	int		i;

	y = m->m_col;
	while (--y > 0)
	{
		x = m->m_row;
		while (--x > 0)
		{
			if (m->map[y][x] == pl->name)
			{
				i = -1;
				while (++i < m->m_row)
					if (m->map[y][i] == 'O' || m->map[y][i] == 'X')
						return (1);
			}
			if (m->map[0][y] == pl->name ||
				m->map[m->m_col - 1][x] == pl->name)
				return (0);
		}
	}
	return (0);
}

void			get_player_info(t_player *pl, t_map *m)
{
	char	*line;
	int		i;

	i = -1;
	get_next_line(0, &line);
	while (line[++i])
		if (line[i] >= 48 && line[i] <= 57)
			m->nbr.nbr = ft_atoi(&line[i]);
	pl->name = (m->nbr.nbr == 1) ? 'O' : 'X';
	get_next_line(0, &line);
	i = -1;
	while (!(line[i] >= 48 && line[i] <= 57))
		++i;
	m->m_col = ft_atoi(&line[i]);
	while (line[i] >= 48 && line[i] <= 57)
		++i;
	m->m_row = ft_atoi(&line[i++]);
}

void			save_game_board(t_map *m, t_piece *p)
{
	char	*line;

	m->m_join = "\0";
	p->p_join = "\0";
	p->lines = -1;
	m->lines = 0;
	while (m->lines < m->m_col && get_next_line(0, &line))
	{
		if (line[0] >= 48 && line[0] <= 57)
		{
			m->m_join = ft_strjoin(ft_strjoin(m->m_join, &line[4]), "\n");
			m->lines++;
		}
	}
	m->map = ft_strsplit(m->m_join, '\n');
	get_next_line(0, &line);
	p->p_col = ft_atoi(&line[6]);
	p->p_row = ft_atoi(&line[8]);
	while (++p->lines < p->p_col && get_next_line(0, &line))
		p->p_join = ft_strjoin(ft_strjoin(p->p_join, line), "\n");
	p->piece = ft_strsplit(p->p_join, '\n');
}

int				main(void)
{
	t_player	pl;
	t_piece		p;
	t_map		m;
	int			i;

	get_player_info(&pl, &m);
	while (1)
	{
		if (m.nbr.nbr == 1 || m.nbr.nbr == 2)
		{
			i = -1;
			save_game_board(&m, &p);
			while (++i < (&m)->m_col && i < (&m)->m_row)
				if ((&m)->map[i][0] == (&pl)->name &&
					(((&m)->map[0][i] == 'O' || (&m)->map[0][i] == 'X') &&
					(&m)->map[i][(&m)->m_row - 1] == (&pl)->name))
					ft_place_left(&m, &pl, &p);
			(check_player_pos(&m, &pl)) ?
			ft_move_top(&m, &pl, &p) : ft_move_bot(&m, &pl, &p);
			if ((&pl)->cantmv == 1)
				ft_move_bot(&m, &pl, &p);
			if ((&pl)->finish == 1)
				return (1);
		}
	}
}
