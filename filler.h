/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:10:39 by mntumba           #+#    #+#             */
/*   Updated: 2018/09/22 08:10:45 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1

typedef struct	s_player
{
	int			nbr;
	int			cantmv;
	int			finish;
	char		name;

}				t_player;

typedef struct	s_map
{
	int			m_col;
	int			m_row;
	int			lines;
	t_player	nbr;
	int			x;
	int			y;
	int			tmp;
	char		*m_join;
	char		**map;
}				t_map;

typedef struct	s_piece
{
	int			p_col;
	int			p_row;
	int			lines;
	int			x;
	int			y;
	int			i;
	int			j;
	int			p_count;
	char		*p_join;
	char		**piece;
}				t_piece;

void			ft_move_top(t_map *m, t_player *pl, t_piece *p);
void			ft_move_bot(t_map *m, t_player *pl, t_piece *p);
void			ft_place_left(t_map *m, t_player *pl, t_piece *p);
void			ft_get_map(t_map *m, t_piece *p);
int				get_next_line(int const fd, char **line);
void			ft_putnbr(int n);
int				ft_atoi(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_strsplit(char const *s, char c);

#endif
