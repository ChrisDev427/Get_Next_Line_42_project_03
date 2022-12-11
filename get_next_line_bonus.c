/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:26 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/11 20:05:57 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	int		size;
	char	buf[BUFFER_SIZE + 1];
puts("ft_read");
	size = 1;
	buf[0] = '\0';
	if (saved) {printf("if saved existe ft_read");
		*s = ft_strjoin(*s, saved);}
	while (size != 0 && !ft_strchr(buf, '\n'))
	{puts("while");
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		*s = ft_strjoin(*s, buf);
	}
	printf("buf after while -> %s\n", buf);
	if (size != 0 && *buf)
	{puts("if-01");
		ft_strcpy(saved, ft_strchr(buf, '\n') + 1);
		ft_cut_after_nl(*s);
		printf("saved from ft_read -> %s\n", saved);
	}
	if (!ft_strchr(*s, '\n'))
	{puts("if-02");
		*saved = 0;
	}
}

char	*get_next_line_bonus(int fd)
{
	char		*s;
	static char	saved[BUFFER_SIZE + 1];
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	s = ft_strdup("");
	if (*saved && ft_strchr(saved, '\n'))
	{puts("if gnl");
		s = ft_strjoin(s, saved);
		ft_cut_after_nl(s);
		ft_strcpy(saved, ft_strchr(saved, '\n' ) + 1);
	}
	else
	{puts("else gnl");
		ft_read(&s, saved, fd);
		if (ft_strlen(s) == 0)
		{puts("free");
			free(s);
			return (NULL);
		}
	}
	return (s);
}
