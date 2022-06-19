/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:46:19 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 23:05:11 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_empty_rows(t_base *piece)
{
	int	empty;
	int	i;
	int	j;

	i = piece->height - 1;
	j = piece->length - 1;
	empty = 0;
	while (i > 0 && piece->contents[i][j] != '*')
	{
		while (j > 0 && piece->contents[i][j] != '*')
		{
			j--;
		}
		if (piece->contents[i][j] != '*')
		{
			empty++;
			j = piece->length - 1;
			i--;
		}
	}	
	return (empty);
}

static int	check_empty_columns(t_base *piece)
{
	int	empty;
	int	i;
	int	j;

	i = 0;
	j = piece->length - 1;
	empty = 0;
	while (j > 0 && piece->contents[i][j] != '*')
	{
		while (i < piece->height - 1 && piece->contents[i][j] != '*')
		{
			i++;
		}
		if (piece->contents[i][j] != '*')
		{
			empty++;
			i = 0;
			j--;
		}
	}
	return (empty);
}

int	update_piece(t_base *piece, char *row)
{
	static int	i;
	int			j;

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

void	insert_piece(int x, int y, int fd)
{
	ft_putstr_fd("Inserted piece in: [", fd);
	ft_putnbr_fd(x, fd);
	ft_putstr_fd("],[", fd);
	ft_putnbr_fd(y, fd);
	ft_putstr_fd("]\n", fd);
	ft_putnbr_fd(x, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(y, 1);
	ft_putchar_fd('\n', 1);
}

/*
 *	Check if piece placed would be outside of map.
 */
int	outside_of_map(t_base *piece, t_base *map, t_player *player)
{
	int	rows;
	int	columns;

	rows = check_empty_rows(piece);
	columns = check_empty_columns(piece);
	if (piece->height - rows > map->height - player->x + 1
		|| piece->length - columns > map->length - player->y + 1)
		return (1);
	return (0);
}
