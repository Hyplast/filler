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
