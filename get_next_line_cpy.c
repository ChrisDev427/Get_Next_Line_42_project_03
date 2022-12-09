/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:26 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/09 15:28:07 by chmassa          ###   ########.fr       */
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

char	*ft_read(char *buf, char *saved, int fd)
{
	char	*s;
	int		size;

	size = 1;
	s = "";
	if (saved)
		s = ft_strjoin(s, saved);
	while (size != 0 && !ft_strchr(buf, '\n'))
	{//puts("while");
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		s = ft_strjoin(s, buf);
	//	printf("size = %d\n", size);
	//	printf("s in while = %s\n", s);
	}
	if (size != 0 && *buf)
		ft_strcpy(saved, ft_strchr(buf, '\n')+1);
		ft_cut_after_nl(s);
	if (!ft_strchr(s, '\n'))
		*saved = 0;
		if (size == 0 && !*saved && ft_strlen(s) == 0)
		{//puts("free");
		//	free(s);
			puts("free");
			*s = 0;
		}
	return (s);
}

char	*get_next_line(int fd)
{
	char		*s;
	char		buf[BUFFER_SIZE + 1];
	static char	saved[BUFFER_SIZE + 1];
	
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, buf, 0))
		return (NULL);
	s = "";
	buf[0] = '\0';
	
	if (*saved && ft_strchr(saved, '\n'))
	{//puts("AAA");
		s = ft_strjoin(s, saved);
		ft_cut_after_nl(s);
		ft_strcpy(saved, ft_strchr(saved, '\n')+1);
	}
	else
	{//puts("BBB");
		s = ft_read(buf, saved, fd);
		if (ft_strlen(s) == 0)
		{
			free(s);
			return (NULL);
		}
		/*
		s = ft_strjoin(s, saved);
		while (size != 0 && !ft_strchr(buf, '\n'))
		{
			size = read(fd, buf, BUFFER_SIZE);
			buf[size] = '\0';
			s = ft_strjoin(s, buf);	
			if (size == 0 && !*saved && ft_strlen(s) == 0)
			{
				free(s);
				return (NULL);
			}
		}
		if (size != 0 && *buf)
			ft_strcpy(saved, ft_strchr(buf, '\n')+1);
			ft_cut_after_nl(s);	*/
	}
//	printf("last saved = %s\n", saved);
//	if (!ft_strchr(s, '\n'))
//		*saved = 0;
	return (s);                                                        
}
