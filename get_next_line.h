/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:32:45 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/11/29 21:29:32 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_free(void *str);
char	*ft_strdup(const char *s1);
char	*ft_checkfree(char *str1);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_rightover(int pos, char *buf, void *ptr);
char	*ft_insert_ro(char *str, char *rtn);

#endif