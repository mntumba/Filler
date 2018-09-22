/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:11:25 by mntumba           #+#    #+#             */
/*   Updated: 2018/09/22 08:11:28 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void			ft_putnbr(int n)
{
	unsigned int	nbr;
	char			c;

	nbr = (n < 0 && write(1, "-", 1)) ? -n : n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		c = nbr % 10 + 48;
		write(1, &c, 1);
	}
	else
	{
		c = nbr + 48;
		write(1, &c, 1);
	}
}

int				ft_atoi(const char *str)
{
	int		sign;
	int		res;

	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' ||
			*str == '\r' || *str == ' ')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - 48;
	return (res * sign);
}

char			*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = -1;
	while (++i <= size)
		str[i] = 0;
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	if (!s1 || !s2 || !(new_str = ft_strnew(len1 + len2)))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len1)
		*(new_str + i) = *(s1 + i);
	while (++j < len2)
		*(new_str + i++) = *(s2 + j);
	return (new_str);
}
