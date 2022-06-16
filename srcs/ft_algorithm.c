/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:51:14 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 14:25:36 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


/*			player
 *		   player_char = 'X'
 *		   enemy_char = 'O'; x = 0 and y=1
 */

/*			piece
 *		   y012		size = 9; 
 *		  0 .*.		height = 3
 *		  1 .*.		length = 3
 *		x 2 ...		non_empty = 2
 */

/*			map
 *		   y01234
 *		  0 .....	size = 25
 *		  1 ..X..	height = 5
 *		  2 .OOO.	length = 5
 *		x 3 .....	non_empty = 4
 */

// if (map->contents[player->x][player->y] == 'X' && 
/*
 *	Loop through piece and if it is '*' find the distance to 
 *	nearest enemy. Calculate the average distance for all
 *	of the '*'.
 */
float	loop_piece(t_base *piece, t_base *map, t_player *player, int dist)
{
	int	i;
	int	j;
	int	count;
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

/*
 * 	Find the distance to nearest enemy char. Recursively increase the distance.
 *	@return (int) Distance to neareast enemy char.
 */
int dist_n_away(t_base *piece, t_base *map, t_player *player, int dist)
{
	int	i;
	int	j;

	i = -1 * dist;
	j = -1 * dist;
	while (i <= dist)
	{
		while (j <= dist)
		{
			if (i + map->x >= 0 && j + map->y >= 0
				&& i + map->x <= map->height && j + map->y <= map->length)
			{
				if (map->contents[map->x + i][map->y + j] == player->enemy_char)
					return (dist);
			}
			j++;
		}
		j = -1 * dist;
		i++;
	}
	return (dist_n_away(piece, map, player, dist + 1));
}

/*		   y01234
 *		  0 .....
 *		  1 ..XX.
 *		  2 .OOO.
 *		x 3 .....
 */
/*
static int	calc_dist_to_enemy(t_base *piece, t_base *map, t_player player)
{
	int	distance;
	int	i;
	int j;
	float	sum;

	distance = 1;
	i = 0;
	j = 0;
	sum = 0;
	while (i < map->height)
	{
		while (j < map->length)
		{
			if (map->contents[i][x] == player->char_char)
				
			while (piece->non_empty < 4)
				sum += dist_n_away(piece, map, player, distance); 
			j++;		
		}
		j = 0;
		i++;
	}
	
	
	return (0);
}
*/

float	le_algo(t_base *piece, t_base *map, t_player *player)
{
	int				distance;
	static float	best_avg_dist_to_enemy;;
	float			avg_distance_to_enemy;

	// if (player->x == 0 && player->y == 0)
	// 	best_avg_dist_to_enemy = 0;
	distance = 1;
	avg_distance_to_enemy = loop_piece(piece, map, player, distance);
	if (avg_distance_to_enemy > best_avg_dist_to_enemy)
	{
		best_avg_dist_to_enemy = avg_distance_to_enemy;
		piece->x = player->x;
		piece->y = player->y;
	}
	return (avg_distance_to_enemy);
}	
/*	while (i < map->height)
	{
		while (j < map->length)
		{
			if (piece->contents[i][j] == player->player)
				avg_distance_to_enemy = calc_dist_to_enemy();
			if (avg_distance_to_enemy > best_avg_dist_to_enemy)
			{
				
			}
			j++;
		}
		j = 0;
		i++;
	}
}
*/
