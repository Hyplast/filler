/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:38:19 by severi            #+#    #+#             */
/*   Updated: 2022/04/20 03:44:32 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	char	*buf;
	int		fd;
	int		read;

	read = 1;
	fd = open("logs.txt", O_WRONLY);
	while(1)	
	{
		//fd = open("logs.txt", O_WRONLY);
		//perror("Error printed by perror: ");
		//ft_putstr_fd("8 2\n", 0);
		ft_putstr_fd("8 2\n", 1);
		ft_putnbr(fd);
		//close(fd);
		while((read = get_next_line(0, &buf)) != 0)
		{
			ft_putstr_fd(buf, fd);
			ft_putchar_fd('\n',fd);
			free(buf);
		}
		
		//fd = open("logs.txt", O_WRONLY);
		ft_putstr_fd("8 3\n", 1);

		//ft_putstr_fd(buf, fd);
		//ft_putchar_fd('\n',fd);
		ft_putchar('\n');
		ft_putstr(buf);
		ft_putchar('\n');
	}
	return (0);
}
