/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:39:24 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 14:20:13 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_player
{
	int			player_num;
	char		player_char;
	char		last_pos;
	char		enemy_char;
	char		enemy_last_pos;
	int			x;
	int			y;
	int			new_x;
	int			new_y;
}				t_player;

typedef struct	s_base
{
	int			**contents;
	int			height;
	int			length;
	int			size;
	int			non_empty;
	int			x;
	int			y;
}				t_base;

int		outside_of_map(t_base *piece, t_base *map, t_player *player, int fd);
void	print_map(t_base *map, int fd);
void	update_map(t_base **map, char *row);
t_base	*create_empty(int height, int length);
int		try_to_fit_it(t_base *piece, t_base *map, t_player *player, int fd);
void	place_piece(t_base *piece, t_base *map, t_player **player, int fd);
int		fit_piece(t_base *piece, t_base *map, t_player **player, int fd);
int		update_piece(t_base **piece, char *row);
int		get_dim(char *str, int d);
void	insert_piece(int x, int y);
void	free_base(t_base **base);
float	le_algo(t_base *piece, t_base *map, t_player *player);
int		dist_n_away(t_base *piece, t_base *map, t_player *player, int dist);

#endif
