/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:38:20 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/09 14:40:23 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd = open("gnlTester/files/43_with_nl", O_RDONLY);;
	int		i = 1;
	char	*s;
//	printf("%d\n", fd);
	while (i <= 3)
	{
		printf("\n----------- appel [%d] ---------------------------\n", i);
		s = get_next_line(fd);
		printf("out : %s", s);
		free(s);
		i++;
	}
//	system ("leaks a.out");

	close(fd);
	return (0);
}
