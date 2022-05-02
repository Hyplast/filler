/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:38:19 by severi            #+#    #+#             */
/*   Updated: 2022/05/02 18:13:08 by severi           ###   ########.fr       */
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
int **create_map(int height, int length)
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
			map[i][j] = 46;
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

/*
 * Create a piece with height x length with "."'s
 */
/*
int **create_piece(int height, int length)
{
	int **piece;
	int i;
	int j;

	i = 0;
	j = 0;
	piece = (int **)malloc(sizeof(int*) * (long unsigned int)height);
	while (i < height)
	{
		piece[i] = (int *)malloc(sizeof(int) * (long unsigned int)length);
		i++;
	}
	i = 0;
	while (i < height)
	{
		while (j < length)
		{
			piece[i][j] = 46;
			j++;
		}
		j = 0;
		i++;
	}
	return (piece);
}
*/

int	**update_map(int **map, char *row)
{
	int	j;
	int i;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (row[i] != ' ')
		i++;
	j = ft_atoi(ft_strsub(row, 0, (size_t)i++));
	while ((size_t)i < ft_strlen(row))
	{
		map[j][k++] = row[i++];
	}
	return (map);
}

void print_map(int **map, int fd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 15) // height
	{
		while (j < 17) // length
		{
			ft_putchar_fd((char)(map[i][j]), fd);
			//printf("%c", map[i][j]);
			j++;
		}
		j = 0;
		//printf("\n");
		ft_putchar_fd('\n', fd);
		i++;
	}
}

int	get_length(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j != 2)
	{
		while (str[i] != ' ')
			i++;
		i++;
		j++;
	}
	j = 0;
	while (ft_isdigit(str[i + j]) == 1)
		j++;
	return (ft_atoi(ft_strsub(str, (unsigned int)i, (unsigned int)j)));
}

int	get_height(char *str)
{
	int i;

	i = 8;
	while (ft_isdigit(str[i]) == 1)
		i++;
	return (ft_atoi(ft_strsub(str, 8, (size_t)i - 8)));
}

int	main(void)
{
	char	*buf;
	int		fd;
	int		read;
	char	*found;
	t_player	player;
	int		**map;

	read = 1;
	player.player_num = 1;
	fd = open("logs.txt", O_WRONLY);
	//map = create_map1(25, 15);
	//print_map(map);
	
	while(1)	
	{
		//fd = open("logs.txt", O_WRONLY);
		//perror("Error printed by perror: ");
		//ft_putstr_fd("8 2\n", 0);
		//ft_putstr_fd("8 2\n", 1);
		//ft_putnbr(fd);
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
		found = NULL;
		//ft_putchar_fd('\n',fd);

		ft_putstr_fd(ft_itoa(player.player_num), fd);
		//ft_putchar_fd('\n',fd);
		free(buf);
		read = get_next_line(0, &buf);
		found = ft_strstr(buf, "Plateau");
		if (found != NULL)
		{
			map = create_map(get_height(buf), get_length(buf));
			print_map(map, fd);
		}
		while((read = get_next_line(0, &buf)) != 0)
		{
			ft_putstr_fd(buf, fd);
			ft_putchar_fd('\n',fd);
			if (ft_isdigit(buf[0]) == 1)
				update_map(map, buf);
			free(buf);
		}
		print_map(map, fd);	

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
