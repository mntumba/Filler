/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:10:53 by mntumba           #+#    #+#             */
/*   Updated: 2018/09/22 08:10:58 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			display(int x, int y)
{
	ft_putnbr(x);
	write(1, " ", 1);
	ft_putnbr(y);
	write(1, "\n", 1);
	return (1);
}

int			checker(t_map *m, t_piece *p, int x, int y)
{
	p->i = -1;
	m->tmp = x;
	p->p_count = 0;
	if ((x > m->m_row || x < 0) || (y > m->m_col || y < 0) ||
	(x + p->p_row > m->m_row) || (y + p->p_col > m->m_col))
		return (0);
	while (++p->i < p->p_col)
	{
		p->j = -1;
		x = m->tmp;
		while (++p->j < p->p_row)
		{
			if (p->piece[p->i][p->j] == '*' && ((m->nbr.nbr == 1 &&
			m->map[y][x] == 'O') || (m->nbr.nbr == 2 && m->map[y][x] == 'X')))
				p->p_count++;
			if (p->piece[p->i][p->j] == '*' && ((m->nbr.nbr == 1 &&
			m->map[y][x] == 'X') || (m->nbr.nbr == 2 && m->map[y][x] == 'O')))
				return (0);
			x++;
		}
		y++;
	}
	return (p->p_count > 1 ? 0 : 1);
}

void		ft_move_top(t_map *m, t_player *pl, t_piece *p)
{
	m->y = -1;
	while (++m->y < m->m_col)
	{
		m->x = -1;
		while (++m->x < m->m_row)
		{
			if (m->map[m->y][m->x] == pl->name)
			{
				p->x = p->p_col;
				while (--p->x >= 0)
				{
					p->y = p->p_row;
					while (--p->y >= 0)
					{
						if (p->piece[p->x][p->y] == '*' &&
						checker(m, p, m->x - p->y, m->y - p->x)
						&& display(m->y - p->x, m->x - p->y))
							return ;
					}
				}
			}
		}
	}
	pl->cantmv = 1;
}

void		ft_move_bot(t_map *m, t_player *pl, t_piece *p)
{
	m->y = m->m_col;
	while (--m->y > 0)
	{
		m->x = m->m_row;
		while (--m->x > 0)
		{
			if (m->map[m->y][m->x] == pl->name)
			{
				p->x = -1;
				while (++p->x < p->p_col)
				{
					p->y = -1;
					while (++p->y < p->p_row)
					{
						if (p->piece[p->x][p->y] == '*' &&
						checker(m, p, m->x - p->y, m->y - p->x)
						&& display(m->y - p->x, m->x - p->y))
							return ;
					}
				}
			}
		}
	}
	pl->finish = 1;
}

void		ft_place_left(t_map *m, t_player *pl, t_piece *p)
{
	m->y = (m->m_col / 2) - 1;
	while (++m->y < m->m_col)
	{
		m->x = -1;
		while (++m->x < m->m_row)
		{
			if (m->map[m->y][m->x] == pl->name)
			{
				p->x = p->p_col;
				while (--p->x >= 0)
				{
					p->y = p->p_row;
					while (--p->y >= 0)
					{
						if (p->piece[p->x][p->y] == '*' &&
						checker(m, p, m->x - p->y, m->y - p->x)
						&& display(m->y - p->x, m->x - p->y))
							return ;
					}
				}
			}
		}
	}
	pl->cantmv = 1;
}
