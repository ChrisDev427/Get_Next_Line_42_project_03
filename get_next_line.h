/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:38:39 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/12 15:06:09 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 84

# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dst, const char *src);
void	ft_cut_after_nl(char *s);
void	ft_read(char **s, char *saved, int fd);
char	*ft_strjoin(char *s1, char *s2, int free);
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *s, int c);

#endif
