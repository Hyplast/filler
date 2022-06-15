/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:46:19 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 22:13:35 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	map_replace_new_chars(t_base *map)
{

	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->length)
		{
			if (map->contents[i][j] == 'x')
				map->contents[i][j] = 'X';
			else if (map->contents[i][j] == 'o')
				map->contents[i][j] = 'O';
			j++;
		}
		j = 0;
		i++;
	}
}

int	place_piece(t_base *piece, t_base *map, t_player *player, int fd)
{
	map_replace_new_chars(map);
	if (fit_piece(piece, map, player, fd) == 0)
	{
		ft_putchar_fd('\n', fd);
		ft_putstr_fd("ERROR: Piece doesnt fit anywhere\n", fd);
		insert_piece(0, 0);
		free_player(&player);
		free_base(&map);
		close(fd);
		return (1);
	}
	insert_piece(piece->x, piece->y);
	ft_putchar_fd(' ', fd);
	return (0);
}

int		fit_piece(t_base *piece, t_base *map, t_player *player, int fd)
{
	int	i;
	int	j;
	int	fits;
	float	best_move;
	float	last_move;

	last_move = 0;
	best_move = 100;
	fits = 0;
	i = 0;
	j = 0;
	while (i + piece->height <= map->height)
	{
		while (j + piece->length <= map->length)
		{
			player->x = i;
			player->y = j;
			ft_putchar_fd('=', fd);	
//			ft_putnbr_fd(player->player_char , fd);
			// ft_putstr_fd(" or :", fd);
			// ft_putnbr_fd((*player)->last_pos , fd);
//			ft_putchar_fd('\n', fd);
/*
			if (!outside_of_map(piece, map, (*player), fd))
				ft_putstr_fd(" outside_of_map is true : \n", fd);
*/
//			ft_putnbr_fd(piece->length , fd);
//			ft_putchar_fd(',', fd);	
//			ft_putnbr_fd(piece->height , fd);
//			ft_putchar_fd('\n', fd);
//			if ((map->contents[i][j] == (*player)->player_char || 
//				map->contents[i][j] == (*player)->last_pos) 
//			 && !outside_of_map(piece, map, (*player), fd))
			if (!outside_of_map(piece, map, player, fd))
			{
				//ft_putstr_fd("going into overlays\n", fd);
				if (try_to_fit_it(piece, map, player, fd) == 1)
				{
					last_move = le_algo(piece, map, player, fd);
					if (last_move < best_move)
					{
						best_move = last_move;
						piece->x = player->x;
						piece->y = player->y;
					}
					fits = 1;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (fits);
}


int		try_to_fit_it(t_base *piece, t_base *map, t_player *player, int fd)
{
	int	count;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	count = 0;
	while (i < piece->height)
	{
		while (j < piece->length)
		{

	//		ft_putstr_fd(" <- piece content : ", fd);
	//		ft_putchar_fd((char)(piece->contents[i][j]), fd);
	//		ft_putstr_fd("\n <- map content :    ", fd);
	//		ft_putchar_fd((char)(map->contents[player->x + i][player->y + j]), fd);
			// ft_putchar_fd('\n', fd);	
			if (piece->contents[i][j] == '*')
			{
				if (map->contents[player->x + i][player->y + j] == player->player_char)
					count++;
				if (map->contents[player->x + i][player->y + j] == player->enemy_char)
					count += 10;
			}
			j++;
		}
		j = 0;
		i++;
	}
//	ft_putstr_fd("number of count: ", fd);
//	ft_putnbr_fd(count,fd);
ft_putstr_fd("L", fd);
	return (count);
}


int	update_piece(t_base *piece, char *row)
{
	static int i;
	int	j;

	j = 0;
	while (piece->length > j)
	{	
		piece->contents[i][j] = row[j];
		j++;
	}
	i++;
	if (i == piece->height)
		i = 0;
	return (1);
}
