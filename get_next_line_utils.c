/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:32:50 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/11/29 12:17:06 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_insert_ro(char *str, char *rtn)
{
	int	index;
	int	l;

	index = -1;
	l = 0;
	while (str[l])
		l++;
	if (!l)
	{
		*str = '\0';
		return (NULL);
	}
	rtn = (char *)malloc(sizeof(char) * l + 1);
	while (str[++index])
		rtn[index] = str[index];
	rtn[index] = '\0';
	str[0] = '\0';
	return (rtn);
}

void	ft_rightover(int pos, char *buf, void *ptr)
{
	char	*rtn;
	int		index;

	index = 0;
	rtn = (char *)ptr;
	while (buf[pos])
	{
		rtn[index] = buf[pos];
		index++;
		pos++;
	}
	rtn[index] = '\0';
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char			*str;
	int				l;
	unsigned int	i;

	if (!s1)
		return (NULL);
	l = 0;
	while (s1[l])
		l++;
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*rtn;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	rtn = (char *)malloc(sizeof(char) * size + 2);
	while (s1[j])
	{
		rtn[i] = s1[j++];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		rtn[i] = s2[j++];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
