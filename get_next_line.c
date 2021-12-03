/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:18:31 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/03 12:26:22 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_nl_pos(char *rtn)
{
	int	index;

	index = -1;
	while (rtn[++index])
		if (rtn[index] == '\n')
			return (index + 1);
	return (0);
}

static char	*ft_nl_line(int pos, char *rtn, void *buf)
{
	char	*n_rtn;
	int		index;

	n_rtn = (char *)malloc(sizeof(char) * pos + 2);
	index = -1;
	while (rtn[++index] && index <= pos)
		n_rtn[index] = rtn[index];
	n_rtn[index] = '\0';
	free((void *)rtn);
	free(buf);
	return (n_rtn);
}

static char	*ft_build_string(char *s1, char *s2, int reading)
{
	char	*rtn;

	s2[reading] = '\0';
	if (!s1)
	{
		rtn = ft_strdup(s2);
		return (rtn);
	}
	if (s1)
	{
		rtn = ft_strjoin(s1, s2);
		free((void *)s1);
		return (rtn);
	}
	return (NULL);
}

static char	*ft_gnl2(int fd, char *rtn, int reading, char *buf)
{
	static char	ro[BUFFER_SIZE];

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 2);
	reading = read(fd, buf, BUFFER_SIZE);
	rtn = ft_insert_ro(&ro[0], rtn);
	if ((!reading && !rtn) || reading < 0)
	{
		free((void *)buf);
		return (NULL);
	}
	buf[reading] = '\0';
	while (!ft_nl_pos(buf) && reading)
	{
		rtn = ft_build_string(rtn, buf, reading);
		reading = read(fd, buf, BUFFER_SIZE);
	}
	if (ft_nl_pos(buf) || ft_nl_pos(rtn))
	{
		rtn = ft_build_string(rtn, buf, reading);
		ft_rightover(ft_nl_pos(rtn), rtn, (void *)ro);
		rtn = ft_nl_line(ft_nl_pos(rtn) - 1, rtn, (void *)buf);
		return (rtn);
	}
	free((void *)buf);
	return (rtn);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	return (ft_gnl2(fd, NULL, 0, NULL));
}
