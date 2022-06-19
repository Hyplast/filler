/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:51:14 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 23:06:11 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
 * 	Find the distance to nearest enemy char. Recursively increase the distance.
 *	@return (int) Distance to neareast enemy char.
 */
static int	dist_n_away(t_base *piece, t_base *map, t_player *player, int dist)
{
	int	i;
	int	j;

	i = -1 * dist;
	j = -1 * dist;
	while (i < dist)
	{
		while (j < dist)
		{
			if (i + map->x > 0 && j + map->y > 0
				&& i + map->x < map->height && j + map->y < map->length)
			{
				if (map->contents[map->x + i][map->y + j] == player->enemy_char)
					return (dist);
			}
			j++;
		}
		j = -1 * dist;
		i++;
	}
	if (dist > map->length - 4)
		return (dist);
	return (dist_n_away(piece, map, player, dist + 1));
}

/*
 *	Loop through piece and if it is '*' find the distance to 
 *	nearest enemy. Calculate the average distance for all
 *	of the '*'.
 */
static float	loop_piece(t_base *piece, t_base *map,
					t_player *player, int dist)
{
	int		i;
	int		j;
	int		count;
	float	sum;

	i = -1;
	j = -1;
	sum = 0;
	count = 0;
	while (++i < piece->height)
	{
		while (++j < piece->length)
		{
			if (piece->contents[i][j] == '*')
			{
				map->x = i + player->x;
				map->y = j + player->y;
				sum += (float)dist_n_away(piece, map, player, dist);
				count++;
			}
		}
		j = -1;
	}
	return (sum / (float)count);
}

float	do_the_algo(t_base *piece, t_base *map, t_player *player)
{
	int				distance;
	float			avg_distance_to_enemy;

	distance = 1;
	avg_distance_to_enemy = loop_piece(piece, map, player, distance);
	return (avg_distance_to_enemy);
}	
