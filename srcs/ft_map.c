/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:49:00 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 22:52:21 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	update_map(t_base *map, char *row)
{
	int		j;
	int		i;
	int		k;
	char	*temp;

	i = 0;
	j = 0;
	k = 0;
	while (row[i] != ' ')
		i++;
	temp = ft_strsub(row, 0, (size_t)i++);
	j = ft_atoi(temp);
	ft_strdel(&temp);
	while ((size_t)i < ft_strlen(row))
		map->contents[j][k++] = (int)row[i++];
}

void	print_map(t_base *map, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->length)
		{
			ft_putchar_fd((char)(map->contents[i][j]), fd);
			j++;
		}
		j = 0;
		ft_putchar_fd('\n', fd);
		i++;
	}
}

int	check_empty_rows(t_base *piece)
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

int	check_empty_columns(t_base *piece)
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

/*
 *	Check if piece placed would be outside of map.
 */
int	outside_of_map(t_base *piece, t_base *map, t_player *player)
{
	int	rows;
	int	columns;

	rows = check_empty_rows(piece);
	columns = check_empty_columns(piece);
	if (piece->height - rows > map->height - player->x
		|| piece->length - columns > map->length - player->y)
		return (1);
	return (0);
}
