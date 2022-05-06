/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:38:19 by severi            #+#    #+#             */
/*   Updated: 2022/05/06 10:06:55 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
 * Create an structure of height x length dimensions of '.''s
 * @params height
 * @params length
 */
t_base	*create_empty(int height, int length)
{
	int 	i;
	int 	j;
	t_base	*base;

	i = 0;
	j = 0;
	base = (t_base*)malloc(sizeof(t_base));
	base->contents = (int **)malloc(sizeof(int*) * (long unsigned int)height);
	while (i < height)
		base->contents[i++] = (int *)malloc(sizeof(int) * (long unsigned int)length);
	i = 0;
	while (i < height)
	{
		while (j < length)
			base->contents[i][j++] = 46;
		j = 0;
		i++;
	}
	base->height = height;
	base->length = length;
	return (base);
}

void	update_map(t_base **map, char *row)
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
		(*map)->contents[j][k++] = (int)row[i++];
	}
}

int	update_piece(t_base **piece, char *row)
{
	static int i;
	int	j;

	j = 0;
	while ((*piece)->length > j)
	{	
		(*piece)->contents[i][j] = row[j];
		j++;
	}
	i++;
	if (i == (*piece)->height)
		i = 0;
	return (1);
}

void print_map(t_base *map, int fd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->height) // height
	{
		while (j < map->length) // length
		{
			ft_putchar_fd((char)(map->contents[i][j]), fd);
			//printf("%c", map[i][j]);
			j++;
		}
		j = 0;
		//printf("\n");
		ft_putchar_fd('\n', fd);
		i++;
	}
}

int	get_dim(char *str, int d)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j != d)
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

void	free_base(t_base **base)
{
	int	i;

	i = 0;
	while (i < (*base)->height)
	{
		free((*base)->contents[i++]);
	}
	free((*base)->contents);
	free((*base));
}

int	chk_piece_fit(t_base *piece, t_base *map)
{
	int	x;
	int	y;
	int	i;
	int	j;
	
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	if (piece->contents[x][y] == map->contents[i][j])
		return (1);
	return (0);
}

void	place_piece(t_base *piece, t_base *map, t_player *player, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->height > i)
	{
		while (map->length > j)
//		while (map->contents[i][j] != player->player_char && 
//				map->contents[i][j] != player->last_pos) 
		{
			if (map->contents[i][j] == player->player_char || 
				map->contents[i][j] == player->last_pos)
			{
				player->x = i;
				player->y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("%d %d\n", player->x, player->y);
	ft_putnbr_fd(player->x ,1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(player->y ,1);
	ft_putchar_fd('\n', 1);
	
	ft_putnbr_fd(player->x ,fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(player->y ,fd);
	ft_putchar_fd('\n', fd);

	chk_piece_fit(piece, map);
//	piece.contents[][]
//	if (piece->height != map->height)
//		ft_putstr_fd("8 3\n", 1);
	
}

int	main(void)
{
	char	*buf;
	int		fd;
	int		read;
	int		row_num;
	char	*found;
	t_player	*player;
	t_base	*map;
	t_base	*piece;

	read = 1;
	row_num = 0;
	player = (t_player*)malloc(sizeof(t_player));
	player->player_num = 1;
	player->player_char = 'O';
	player->last_pos = 'o';
	fd = open("logs.txt", O_WRONLY);
	
	ft_putstr_fd("STARTING NEW LOGGING\n\n", fd);
	//map = create_map1(25, 15);
	//print_map(map);


	
//	while(1)
//	{
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
			player->player_num = 2;
			player->player_char = 'X';
			player->last_pos = 'x';
		}
		found = NULL;
		//ft_putchar_fd('\n',fd);

		ft_putstr_fd(ft_itoa(player->player_num), fd);
		//ft_putchar_fd('\n',fd);
		free(buf);
		read = get_next_line(0, &buf);
		found = ft_strstr(buf, "Plateau");
		if (found != NULL)
		{
			map = create_empty(get_dim(buf, 1), get_dim(buf, 2));
			print_map(map, fd);
		}
		found = NULL;
	
	while(1)
	{
		while((read = get_next_line(0, &buf)) != 0)
		{
			ft_putstr_fd(buf, fd);
			ft_putchar_fd('\n',fd);
			found = ft_strstr(buf, "Piece");
			if (ft_isdigit(buf[0]) == 1)
				update_map(&map, buf);
			else if (found != NULL)
			{
				piece = create_empty(get_dim(buf, 1), get_dim(buf, 2));
				ft_putstr_fd("piece read\n", fd);
				print_map(piece, fd);
				ft_putstr_fd("piece printed\n", fd);

				found = NULL;
			}
			else if (buf[0] == '.' || buf[0] == '*')
			{
				ft_putstr_fd("going into update\n", fd);
				row_num = row_num + update_piece(&piece, buf);
				ft_putstr_fd("coming out of update\n", fd);
				ft_putnbr_fd(piece->height, fd);
				ft_putstr_fd(" == ", fd);
				ft_putnbr_fd(row_num, fd);
				ft_putstr_fd(" are they equal?\n", fd);


				if (piece->height == row_num)	
				{
					printf("piece complete \n");
					ft_putstr_fd("piece complete\n", fd);
					print_map(piece, fd);
					place_piece(piece, map, player, fd);
					ft_putstr_fd("coming out of place_piece\n", fd);

					row_num = 0;
					free_base(&piece);
				}
			}
			ft_strdel(&buf);
		}
		//ft_putstr_fd("printing map\n", fd);
		//print_map(map, fd);

		//fd = open("logs.txt", O_WRONLY);
		
		//ft_putstr_fd(buf, fd);
		//ft_putchar_fd('\n',fd);
		//ft_putchar('\n');
		//ft_putstr(buf);
		//ft_putchar('\n');
	}

	return (0);
}
