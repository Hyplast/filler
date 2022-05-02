/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:38:19 by severi            #+#    #+#             */
/*   Updated: 2022/05/02 16:23:03 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
 * Create a height x length map of 0's
 * @params height
 * @params length
 */
int **create_map1(int height, int length)
{
	int **map;
	int i;
	int j;

	i = 0;
	j = 0;
	map = (int **)malloc(sizeof(int*) * (long unsigned int)height);
	while (i < height)
	{
		map[i] = (int *)malloc(sizeof(int) * (long unsigned int)length);
		i++;
	}
	i = 0;
	while (i < height)
	{
		while (j < length)
		{
			map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

/*
int	**create_map(int x)
{
	int	map1[15][17];
	int map2[24][40];
	int	map3[100][99];

	//map[0] = [0, 0, 0];
	//map[1] = [1, 0, 0];
	//map[2] = [0, 0, 2];
	if (x == 1)
		return (map1);
	else if (x == 2)
		return (map2);
	else if (x == 3)
		return (map3);
	return (map1);
}
*/

void print_map(int **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 25)
	{
		while (j < 15)
		{
			printf("%d", map[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		//ft_putchar('\n');
		i++;
	}
}

int	main(void)
{
//	char	*buf;
//	int		fd;
//	int		read;
//	char	*found;
//	t_player	player;
	int		**map;

//	read = 1;
//	player.player_num = 1;
//	fd = open("logs.txt", O_WRONLY);
	map = create_map1(25, 15);
	print_map(map);
/*	
	while(1)	
	{
		//fd = open("logs.txt", O_WRONLY);
		//perror("Error printed by perror: ");
		//ft_putstr_fd("8 2\n", 0);
		ft_putstr_fd("8 2\n", 1);
		ft_putnbr(fd);
		//close(fd);

		read = get_next_line(0, &buf);
		found = ft_strstr(buf, "exec p1");
		ft_putchar_fd('\n',fd);
		ft_putstr_fd(buf, fd);
		ft_putchar_fd('\n',fd);
		if (found == NULL)
		{
			player.player_num = 2;
		}
		ft_putchar_fd('\n',fd);

		ft_putstr_fd(ft_itoa(player.player_num), fd);
		ft_putchar_fd('\n',fd);
		free(buf);
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
*/
	return (0);
}
