/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:26 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/11 09:27:34 by chmassa          ###   ########.fr       */
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

void	ft_read(char **s, char *buf, char *saved, int fd)
{
	int		size;

	size = 1;
	if (saved)
		*s = ft_strjoin(*s, saved);
	while (size != 0 && !ft_strchr(buf, '\n'))
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		*s = ft_strjoin(*s, buf);
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
	char		buf[BUFFER_SIZE + 1];
	static char	saved[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, buf, 0))
		return (NULL);
	s = ft_strdup("");
	buf[0] = '\0';
	if (*saved && ft_strchr(saved, '\n'))
	{
		s = ft_strjoin(s, saved);
		ft_cut_after_nl(s);
		ft_strcpy(saved, ft_strchr(saved, '\n' ) + 1);
	}
	else
	{
		ft_read(&s, buf, saved, fd);
		if (ft_strlen(s) == 0)
		{
			free(s);
			return (NULL);
		}
	}
	return (s);
}
