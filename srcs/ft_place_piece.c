/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:46:19 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 23:05:11 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	try_to_fit_it(t_base *piece, t_base *map, t_player *player)
{
	int	count;
	int	i;
	int	j;

	i = -1;
	j = -1;
	count = 0;
	while (++i < piece->height)
	{
		while (++j < piece->length)
		{
			if (piece->contents[i][j] == '*')
			{
				if (map->contents[player->x + i][player->y + j]
					== player->player_char)
					count++;
				if (map->contents[player->x + i][player->y + j]
					== player->enemy_char)
					count += 10;
			}
		}
		j = -1;
	}
	return (count);
}

static void	fit_piece_loop(t_base *piece, t_base *map, t_player *player)
{
	if (!outside_of_map(piece, map, player))
	{
		if (try_to_fit_it(piece, map, player) == 1)
		{
			player->last_move = do_the_algo(piece, map, player);
			if (player->last_move < player->best_move)
			{
				player->best_move = player->last_move;
				piece->x = player->x;
				piece->y = player->y;
			}
			player->fits = 1;
		}
	}
}

static int	fit_piece(t_base *piece, t_base *map, t_player *player)
{
	int		i;
	int		j;

	player->best_move = 100;
	player->last_move = 100;
	player->fits = 0;
	i = 0;
	j = 0;
	while (i + piece->height <= map->height)
	{
		while (j + piece->length <= map->length)
		{
			player->x = i;
			player->y = j;
			fit_piece_loop(piece, map, player);
			j++;
		}
		j = 0;
		i++;
	}
	return (player->fits);
}

int	place_piece(t_base *piece, t_base *map, t_player *player)
{
	map_replace_new_chars(map);
	if (fit_piece(piece, map, player) == 0)
	{
		insert_piece(0, 0);
		return (1);
	}
	insert_piece(piece->x, piece->y);
	return (0);
}
