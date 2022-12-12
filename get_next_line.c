/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:26 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/12 15:32:20 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_cut_after_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			s[i +1] = '\0';
		i++;
	}
}

void	ft_read(char **s, char *saved, int fd)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];

	size = 1;
	buf[0] = '\0';
	if (saved)
		*s = ft_strjoin(*s, saved, 0);
	while (size != 0 && !ft_strchr(buf, '\n'))
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		*s = ft_strjoin(*s, buf, 1);
	}
	if (size != 0 && *buf)
	{
		ft_strcpy(saved, ft_strchr(buf, '\n') + 1);
		ft_cut_after_nl(*s);
	}
	if (!ft_strchr(*s, '\n'))
		*saved = 0;
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	saved[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		saved[0] = 0;
		return (NULL);
	}
	s = "";
	if (*saved && ft_strchr(saved, '\n'))
	{
		s = ft_strjoin(s, saved, 0);
		ft_cut_after_nl(s);
		ft_strcpy(saved, ft_strchr(saved, '\n' ) + 1);
	}
	else
	{
		ft_read(&s, saved, fd);
		if (ft_strlen(s) == 0)
		{
			free(s);
			return (NULL);
		}
	}
	return (s);
}
