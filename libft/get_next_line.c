/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:11:13 by mntumba           #+#    #+#             */
/*   Updated: 2018/09/22 08:11:17 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	i = -1;
	while (++i < (int)len + 1)
		if (*(s + i) == c)
			return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char			*s;
	unsigned int	i;
	size_t			len;

	len = 0;
	while (s1[len])
		len++;
	i = -1;
	if (!(s = (char*)malloc(sizeof(*s) * len + 1)))
		return (NULL);
	while (++i < len)
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str_new;
	unsigned int	i;

	i = -1;
	if (!(str_new = ft_strnew(len)) || !s)
		return (NULL);
	while (++i < len)
		str_new[i] = s[start++];
	return (str_new);
}

int		save_line(int fd, char **line, char **s)
{
	int		i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		if (s[fd] != NULL)
		{
			free(s[fd]);
			s[fd] = NULL;
		}
	}
	else if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		s[fd] = ft_strdup(&s[fd][i + 1]);
		if (s[fd][0] == '\0' && s[fd] != NULL)
		{
			free(s[fd]);
			s[fd] = NULL;
		}
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*s[1];
	char			buff[BUFF_SIZE + 1];
	int				i;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		s[fd] = (s[fd] == NULL) ? ft_strnew(1) : s[fd];
		s[fd] = ft_strjoin(s[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (i < 0 || (i == 0 && (s[fd] == NULL || s[fd][0] == '\0')))
		return (i < 0 ? -1 : 0);
	return (save_line(fd, line, s));
}
