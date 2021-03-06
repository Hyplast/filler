/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:39:24 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 23:04:22 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_player
{
	int			player_num;
	char		player_char;
	char		last_pos;
	char		enemy_char;
	char		enemy_last_pos;
	int			x;
	int			y;
	int			fits;
	float		best_move;
	float		last_move;
}				t_player;

typedef struct s_base
{
	int			**contents;
	int			height;
	int			length;
	int			size;
	int			non_empty;
	int			x;
	int			y;
}				t_base;

int			outside_of_map(t_base *piece, t_base *map, t_player *player);
void		print_map(t_base *map, int fd);
void		update_map(t_base *map, char *row);
void		map_replace_new_chars(t_base *map);
t_base		*create_empty(int height, int length);
int			place_piece(t_base *piece, t_base *map, t_player *player);
int			update_piece(t_base *piece, char *row);
int			get_dim(char *str, int d);
void		insert_piece(int x, int y);
void		free_base(t_base **base);
void		free_player(t_player **player);
float		do_the_algo(t_base *piece, t_base *map, t_player *player);
void		put_logs(char *buf, int fd);
void		exchange_player_chars(t_player *player);
t_player	*set_up_player(void);
int			set_up_logging(void);

#endif
