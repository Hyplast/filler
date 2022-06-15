/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:46:19 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 13:25:46 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place_piece(t_base *piece, t_base *map, t_player **player, int fd)
{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
/*	while (map->height > i)
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
*/
	ft_putstr_fd("going into fit_piece\n", fd);

	fit_piece(piece, map, player, fd);
//	le_algo()
	insert_piece((*player)->x, (*player)->y);
	
	ft_putstr_fd("inserted: ", fd);
	ft_putnbr_fd((*player)->x ,fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd((*player)->y ,fd);
	ft_putchar_fd('\n', fd);


//	chk_piece_fit(piece, map);

//	piece.contents[][]
//	if (piece->height != map->height)
//		ft_putstr_fd("8 3\n", 1);
	
}

int		fit_piece(t_base *piece, t_base *map, t_player **player, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i + piece->height <= map->height)
	{
		while (j + piece->length <= map->length)
		{
			(*player)->x = i;
			(*player)->y = j;
//			ft_putstr_fd("into outside_of_map: ", fd);
//			ft_putnbr_fd((*player)->x , fd);
//			ft_putchar_fd(',', fd);	
//			ft_putnbr_fd((*player)->x , fd);
//			ft_putchar_fd('\n', fd);	
			
//			ft_putnbr_fd(map->contents[i][j] , fd);
//			ft_putchar_fd('=', fd);	
//			ft_putnbr_fd((*player)->player_char , fd);
//			ft_putstr_fd(" or :", fd);
//			ft_putnbr_fd((*player)->last_pos , fd);
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
			if (!outside_of_map(piece, map, (*player), fd))
			{
				//ft_putstr_fd("going into overlays\n", fd);

				if (try_to_fit_it(piece, map, (*player), fd) == 1)
					return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
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
